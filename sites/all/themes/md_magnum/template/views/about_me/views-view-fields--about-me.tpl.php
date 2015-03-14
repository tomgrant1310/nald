<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */
?>
<!-- About header -->
<div style="background-image: url('<?php print file_create_url($row->field_field_am_background_image[0]['rendered']['#item']['uri']);?>')" class="header bottom">
  <div class="header-center">
    <div class="centerdiv text-white">

      <!-- Text on the header -->
      <h4 class="bigtext uppercase letterspace bold"><?php print $fields['field_am_description']->content;?></h4>
      <h6 class="bigtext serif italic"><?php print $fields['field_am_sub_description']->content;?></h6>

    </div>
  </div>
</div>

<!-- Circle avatar -->
<img src="<?php print file_create_url($row->field_field_am_image[0]['raw']['uri']);?>" alt="about me avatar" class="about-avatar">

<!-- About introduction -->
<div class="row">
  <div class="ten columns center margin-bottom">
    <h2 class="text-color"><?php print $fields['title']->content;?></h2>
    <p class="big thin"><?php if($row->field_body) {print $row->field_body[0]['raw']['value'];}?></p>
  </div>
</div>


<!-- 3 Columns -->
<div class="row">
  <?php foreach ($row->field_field_am_details as $key => $value):?>
  <?php $raw_value = $value['raw']['value'];?>
  <!-- Column 1 -->
  <div class="four columns">
    <h4><?php print $value['rendered']['entity']['field_collection_item'][$raw_value]['field_detail_title']['#items'][0]['value'];?></h4>
    <p><?php print $value['rendered']['entity']['field_collection_item'][$raw_value]['field_detail_body']['#items'][0]['value'];?></p>
  </div>
  <?php endforeach;?>

</div>
