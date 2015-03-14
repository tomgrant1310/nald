<?php

include_once './' . drupal_get_path('theme', 'md_magnum') . '/inc/template.process.inc';
include_once './' . drupal_get_path('theme', 'md_magnum') . '/inc/template.view.process.inc';
include_once './' . drupal_get_path('theme', 'md_magnum') . '/inc/template.node.process.inc';
/**
 * Implements theme_menu_tree().
 */
function md_magnum_menu_tree($variables) {
    return '<ul class="menu clearfix">' . $variables['tree'] . '</ul>';
}

/**
 * Implements theme_field__field_type().
 */
function md_magnum_field__taxonomy_term_reference($variables) {
    $output = '';

    // Render the label, if it's not hidden.
    if (!$variables['label_hidden']) {
        $output .= '<h3 class="field-label">' . $variables['label'] . ': </h3>';
    }

    // Render the items.
    $output .= ($variables['element']['#label_display'] == 'inline') ? '<ul class="links inline">' : '<ul class="links">';
    foreach ($variables['items'] as $delta => $item) {
        $output .= '<li class="taxonomy-term-reference-' . $delta . '"' . $variables['item_attributes'][$delta] . '>' . drupal_render($item) . '</li>';
    }
    $output .= '</ul>';

    // Render the top-level DIV.
    $output = '<div class="' . $variables['classes'] . (!in_array('clearfix', $variables['classes_array']) ? ' clearfix' : '') . '">' . $output . '</div>';

    return $output;
}

/**
 * Override of theme('textarea').
 * Deprecate misc/textarea.js in favor of using the 'resize' CSS3 property.
 */
function md_magnum_textarea($variables) {
    $element = $variables['element'];
    $element['#attributes']['name'] = $element['#name'];
    $element['#attributes']['id'] = $element['#id'];
    $element['#attributes']['cols'] = $element['#cols'];
    $element['#attributes']['rows'] = $element['#rows'];
    _form_set_class($element, array('form-textarea'));

    $wrapper_attributes = array(
        'class' => array('form-textarea-wrapper'),
    );

    // Add resizable behavior.
    if (!empty($element['#resizable'])) {
        $wrapper_attributes['class'][] = 'resizable';
    }

    $output = '<div' . drupal_attributes($wrapper_attributes) . '>';
    $output .= '<textarea' . drupal_attributes($element['#attributes']) . '>' . check_plain($element['#value']) . '</textarea>';
    $output .= '</div>';
    return $output;
}

/**
 * @param $variables
 * @return Main menu
 */
function md_magnum_links__system_main_menu($variables) {
    $html = "<div>\n";
    $html .= "  <ul>\n";
    foreach ($variables['links'] as $link) {
        $html .= "<li>".l($link['title'], $link['path'].$link['menu_scrollto_path'], $link)."</li>";
    }
    $html .= "  </ul>\n";
    $html .= "</div>\n";

    return $html;
}

function phptemplate_preprocess_page(&$vars){
    if ( isset($_GET['ajax']) && $_GET['ajax'] == 1 ) {
        $vars['template_file'] = 'page-ajax';
    }
}

/**
 * @param $form
 * @param $form_state
 * @param $form_id
 */
function md_magnum_form_alter(&$form, &$form_state, $form_id) {
    if (strpos($form_id,"webform_client_form") === false) {
        switch ($form_id) {
            case 'user_login':
                $form['name']['#prefix'] = '<div class="six columns">';
                $form['name']['#suffix'] = '</div>';
                $form['pass']['#prefix'] = '<div class="six columns">';
                $form['pass']['#suffix'] = '</div>';
                $form['actions']['submit']['#value'] = t('Log In');
                break;
        }
    } else {
        $form['actions']['submit']['#prefix'] = '<div class="twelve columns">';
        $form['actions']['submit']['#suffix'] = '</div>';
        $form['actions']['submit']['#attributes'] = array(
            'class' => array('submit'),
            'id'    => array('submit'),
        );
        $form['actions']['submit']['#value'] = 'Send Message';
    }


}
/**
 * Process variables for comment.tpl.php.
 *
 * @see comment.tpl.php
 */
function md_magnum_preprocess_comment(&$variables) {
    $comment = $variables['elements']['#comment'];
    $node = $variables['elements']['#node'];
    $variables['comment']   = $comment;
    $variables['node']      = $node;
    $variables['author']    = theme('username', array('account' => $comment));

    $variables['created']   = format_date($comment->created);

    // Avoid calling format_date() twice on the same timestamp.
    if ($comment->changed == $comment->created) {
        $variables['changed'] = $variables['created'];
    }
    else {
        $variables['changed'] = format_date($comment->changed);
    }

    $variables['new']       = !empty($comment->new) ? t('new') : '';
    $variables['picture']   = theme_get_setting('toggle_comment_user_picture') ? theme('user_picture', array('account' => $comment)) : '';
    $variables['signature'] = $comment->signature;

    $uri = entity_uri('comment', $comment);
    $uri['options'] += array('attributes' => array('class' => 'permalink', 'rel' => 'bookmark'));

    $variables['title']     = l($comment->subject, $uri['path'], $uri['options']);
    $variables['permalink'] = l(t('Permalink'), $uri['path'], $uri['options']);
    $variables['submitted'] = t('Submitted by !username on !datetime', array('!username' => $variables['author'], '!datetime' => $variables['created']));

    // Preprocess fields.
    field_attach_preprocess('comment', $comment, $variables['elements'], $variables);

    // Helpful $content variable for templates.
    foreach (element_children($variables['elements']) as $key) {
        $variables['content'][$key] = $variables['elements'][$key];
    }

    // Set status to a string representation of comment->status.
    if (isset($comment->in_preview)) {
        $variables['status'] = 'comment-preview';
    }
    else {
        $variables['status'] = ($comment->status == COMMENT_NOT_PUBLISHED) ? 'comment-unpublished' : 'comment-published';
    }

    // Gather comment classes.
    // 'comment-published' class is not needed, it is either 'comment-preview' or
    // 'comment-unpublished'.
    if ($variables['status'] != 'comment-published') {
        $variables['classes_array'][] = $variables['status'];
    }
    if ($variables['new']) {
        $variables['classes_array'][] = 'comment-new';
    }
    if (!$comment->uid) {
        $variables['classes_array'][] = 'comment-by-anonymous';
    }
    else {
        if ($comment->uid == $variables['node']->uid) {
            $variables['classes_array'][] = 'comment-by-node-author';
        }
        if ($comment->uid == $variables['user']->uid) {
            $variables['classes_array'][] = 'comment-by-viewer';
        }
    }
}
/**
 * Check file path upload in theme setting
 */
function md_magnum_theme_setting_check_path($path) {
    $path_scheme = file_uri_scheme($path);
    if ($path_scheme == 'public') {
        $return_path = file_create_url($path);
    } else if (($path_scheme == 'http') || ($path_scheme == 'https')) {
        $return_path = $path;
    } else {
        $return_path = file_create_url(file_build_uri($path));
    }
    return $return_path;
}
