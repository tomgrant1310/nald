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

<?php
if(isset($row->field_field_multimedia)) {
    $multimedia = $row->field_field_multimedia;
    $media_content = '';
    $type_arr = array();
        if(count($multimedia) > 1) {
            foreach($multimedia as $key2 => $item) {
                $raw_value = $item['raw']['value'];
                $field_media_items = $item['rendered']['entity']['field_collection_item'][$raw_value]['field_media']['#items'];
                $field_image_big_text = $item['rendered']['entity']['field_collection_item'][$raw_value]['field_image_big_text']['#items'][0]['value'];
                $field_image_sub_text = $item['rendered']['entity']['field_collection_item'][$raw_value]['field_image_sub_text']['#items'][0]['value'];
                $type_arr[] = $field_media_items[0]['file']->type;
                if(in_array('audio',$type_arr) || in_array('video',$type_arr)){
                    $media_content .= '<li>'.render($multimedia[$key2]['rendered']['entity']['field_collection_item'][$raw_value]['field_media'][$key2]).'</li>';
                } else {
                    $image = file_create_url($field_media_items[0]['file']->uri);
                    $media_content .= '<li>
                        <div style="background-image: url('.$image.')" class="header">
                            <div class="header-center">
                                <div class="centerdiv text-white">
                                    <h4 class="bigtext uppercase letterspace bold">'.$field_image_big_text.'</h4>
                                    <h6 class="bigtext serif italic">'.$field_image_sub_text.'</h6>
                                    </div>
                                </div>
                        </div>
                    </li>';
                }
            }
        } else {
            $raw_value = $multimedia[0]['raw']['value'];
            $field_media_items = $multimedia[0]['rendered']['entity']['field_collection_item'][$raw_value]['field_media']['#items'];
            if(in_array('audio',$type_arr) || in_array('video',$type_arr)) {
                $media_content .= '<li>'.render($multimedia[0]['rendered']['entity']['field_collection_item'][$raw_value]['field_media'][0]).'</li>';
            } else {
                $image = file_create_url($field_media_items[0]['file']->uri);
                $media_content .= '
                    <div style="background-image: url('.$image.')" class="header">
                        <div class="header-center">
                            <div class="centerdiv text-white">
                                <h4 class="bigtext uppercase letterspace bold">'.$field_image_big_text.'</h4>
                                <h6 class="bigtext serif italic">'.$field_image_sub_text.'</h6>
                                </div>
                            </div>
                    </div>
                ';
            }
        }

}
?>
<?php if (isset($media_content) && $media_content != null):?>
<!-- Featured work slider -->
<div class="featured-work-slider flexslider">
    <ul class="slides">
        <?php print $media_content;?>
    </ul>
</div>
<?php endif;?>
<!-- Intro text -->
<div class="row">
    <div class="ten columns center">
        <h2 class="text-color"><?php print $fields['title']->content;?></h2>
        <p class="big thin"><?php if($row->field_body) {print $row->field_body[0]['raw']['value'];}?></p>
    </div>
</div>


<!-- 3 Columns -->
<div class="row">
<?php
$description = $row->field_field_description;
foreach ($description as $key =>$des):
    $raw_val = $des['raw']['value'];
    $des_collection = $des['rendered']['entity']['field_collection_item'][$raw_val];
?>
    <!-- Column 1 -->
    <div class="four columns">
        <p><i class="fa <?php print $des_collection['field_icon'][0]['#icon'];?> icon huge"></i></p>
        <h4><?php print render($des_collection['field_title']);?></h4>
        <?php print render($des_collection['field_body']);?>
    </div>
<?php endforeach;?>
</div>
