<?php

/**
 * @file
 * Main view template.
 *
 * Variables available:
 * - $classes_array: An array of classes determined in
 *   template_preprocess_views_view(). Default classes are:
 *     .view
 *     .view-[css_name]
 *     .view-id-[view_name]
 *     .view-display-id-[display_name]
 *     .view-dom-id-[dom_id]
 * - $classes: A string version of $classes_array for use in the class attribute
 * - $css_name: A css-safe version of the view name.
 * - $css_class: The user-specified classes names, if any
 * - $header: The view header
 * - $footer: The view footer
 * - $rows: The results of the view query, if any
 * - $empty: The empty text to display if the view is empty
 * - $pager: The pager next/prev links to display, if any
 * - $exposed: Exposed widget form/info to display
 * - $feed_icon: Feed icon to display, if any
 * - $more: A link to view more, if any
 *
 * @ingroup views_templates
 */
?>
<?php
$current_display = $view->current_display;
$display_title = $view->display[$current_display]->display_title;
if(isset($view->display[$current_display]->display_options['display_description'])) {
    $display_description = $view->display[$current_display]->display_options['display_description'];
}
?>
<!-- The title -->
<div class="row">
    <div class="twelve columns title">
        <h1><?php if(isset($view->human_name)) {print $view->human_name;}?></h1>
        <hr>
    </div>
</div>

<div class="<?php print $classes; ?>">
    <?php print render($title_prefix); ?>
    <?php if ($title): ?>
        <?php print $title; ?>
    <?php endif; ?>
    <?php print render($title_suffix); ?>
    <?php if ($header): ?>
        <div class="view-header">
            <?php print $header; ?>
        </div>
    <?php endif; ?>

    <?php if ($exposed): ?>
        <div class="view-filters">
            <?php print $exposed; ?>
        </div>
    <?php endif; ?>

    <?php if ($attachment_before): ?>
        <div class="attachment attachment-before">
            <?php print $attachment_before; ?>
        </div>
    <?php endif; ?>

<!-- About us header -->
    <?php if(theme_get_setting('enable_team_header','md_magnum') == '1'):
        $team_bg_path = md_magnum_theme_setting_check_path(theme_get_setting('team_background_path','md_magnum'));?>
        <div style="background-image: url('<?php print $team_bg_path;?>')" class="header center">
            <div class="header-center">
                <div class="centerdiv text-white">
                    <!-- Text on the header -->
                    <h4 class="bigtext uppercase letterspace bold"><?php print theme_get_setting('team_big_text','md_magnum');?></h4>
                    <h6 class="bigtext serif italic"><?php print theme_get_setting('team_sub_text','md_magnum');?></h6>
                </div>
            </div>
        </div>
    <?php endif;?>

<!-- About introduction -->
<div class="row">
    <div class="ten columns center margin-bottom">
        <h2 class="text-color"><?php if(isset($display_title)) {print $display_title;}?></h2>
        <p class="big thin"><?php if(isset($display_description)) {print $display_description;}?></p>
    </div>
</div>


<!-- Employees -->
<div class="row margin">

    <?php if ($rows): ?>
            <?php print $rows; ?>
    <?php elseif ($empty): ?>
        <div class="view-empty">
            <?php print $empty; ?>
        </div>
    <?php endif; ?>

    <?php if ($pager): ?>
        <?php print $pager; ?>
    <?php endif; ?>

    <?php if ($attachment_after): ?>
        <div class="attachment attachment-after">
            <?php print $attachment_after; ?>
        </div>
    <?php endif; ?>

    <?php if ($more): ?>
        <?php print $more; ?>
    <?php endif; ?>

    <?php if ($footer): ?>
        <div class="view-footer">
            <?php print $footer; ?>
        </div>
    <?php endif; ?>

    <?php if ($feed_icon): ?>
        <div class="feed-icon">
            <?php print $feed_icon; ?>
        </div>
    <?php endif; ?>

</div><?php /* class view */ ?>
</div>

