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
<div class="three columns tablet-six columns medium-six columns small-twelve employeeblock">
    <div class="hoverimg">
        <img src="<?php if(isset($row->field_field_au_avatar) && $row->field_field_au_avatar != null) {print file_create_url($row->field_field_au_avatar[0]['rendered']['#item']['uri']);}?>" alt="employee-4">

        <div class="mask">
            <span>
            <?php if(isset($row->field_field_au_social) && $row->field_field_au_social != null){
                foreach ($row->field_field_au_social as $key => $value) {
                    $raw_value = $value['raw']['value'];
                    print '<a href="'.$value['rendered']['entity']['field_collection_item'][$raw_value]['field_social_link']['#items'][0]['value'].'">'.'<i class="'.$value['rendered']['entity']['field_collection_item'][$raw_value]['field_social_icon']['#items'][0]['bundle'].' '.$value['rendered']['entity']['field_collection_item'][$raw_value]['field_social_icon']['#items'][0]['icon'].'"></i></a>';
                }
            }
            ?>
            </span>
        </div>
    </div>
    <h4 class="margin-top"><?php print $fields['title']->content;?></h4>
    <h6 class="serif italic text-light"><?php print $fields['field_au_job']->content;?></h6>
    <?php print $fields['body']->content;?>
</div>
