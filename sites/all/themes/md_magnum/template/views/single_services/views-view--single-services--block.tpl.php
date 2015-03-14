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
<div class="row">
  <div class="twelve columns">


    <!-- The title -->
    <div class="title">
      <h1><?php if(isset($display_title)) {print $display_title;}?></h1>
      <hr>
    </div>


    <!-- Slider controls -->
    <h2 class="text-color"><?php if(isset($display_description)) {print $display_description;}?></h2>
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
    <p>
      <a class="services-prev" href="#"><i class="icon-left-open icon arrow-next outline color attached"></i></a>
      <a class="services-next" href="#"><i class="icon-right-open icon arrow-prev outline color attached"></i></a>
    </p>


  </div>
</div>


<!-- Services slider -->
<div class="row">
  <div class="list_carousel">
    <ul class="services-slider">

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

    </ul>
    <div class="clearfix"></div>
  </div>
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

</div>

