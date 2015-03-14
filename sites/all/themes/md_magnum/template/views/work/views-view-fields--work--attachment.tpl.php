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
global $base_url;
if(isset($row->field_field_multimedia)) {
    $multimedia = $row->field_field_multimedia;
    $thumbnail_url = file_create_url($row->field_field_thumbnail[0]['rendered']['#item']['uri']);
    $thumbnail_name = $row->field_field_thumbnail[0]['rendered']['#item']['filename'];
    $media_content = '';
    $slide_content = '';
        $raw_value = $multimedia[0]['raw']['value'];
        $field_media_items = $multimedia[0]['rendered']['entity']['field_collection_item'][$raw_value]['field_media']['#items'];
        $count = count($multimedia);
        if($count == 1) {
            $file_type = $field_media_items[0]['file']->type;
            if($file_type == 'video') {
                $filemime = $field_media_items[0]['file']->filemime;
                $file_url = file_create_url($field_media_items[0]['file']->uri);
                $media_content .= '<div class="four columns medium-six columns small-twelve columns"><div class="portfolio-thumb">';
                if($filemime == 'video/youtube'){
                    $media_content .= '<a class="popup-youtube" href="'.$file_url.'">';
                }
                if($filemime == 'video/vimeo'){
                    $media_content .= '<a class="popup-vimeo" href="'.$file_url.'">';
                }
                if($filemime == 'video/mp4'){
                    $media_content .= '<a class="popup-video" href="#popup-video"><div id="popup-video" class="white-popup mfp-hide"><video controls="controls" width="100%" height="400" source="'.$file_url.'" type="video/mp4"></video></div>';
                }
                $media_content .= '<img alt="'.$thumbnail_name.'" src="'.$thumbnail_url.'">
                        <i class="fontello icon-video"></i>
                        <b>'.$fields['title']->content.'</b>
                        <em>Video Popup</em>
                    </a>
                </div></div>';
            }
            if($file_type == 'image') {
                $file_url = file_create_url($field_media_items[0]['file']->uri);
                $media_content = '<!-- Portfolio thumb 1 -->
                    <div class="four columns medium-six columns small-twelve columns"><div class="portfolio-thumb">';

                $media_content .= '<a class="popup" href="'.$file_url.'">';

                $media_content .= '<img alt="'.$thumbnail_name.'" src="'.$thumbnail_url.'">
                        <i class="fontello icon-camera"></i>
                        <b>'.$fields['title']->content.'</b>
                        <em>Image Popup</em>
                    </a>
                </div></div>';
            }
            if($file_type == 'audio') {
                $file_url = file_create_url($field_media_items[0]['file']->uri);
                $filemime = $field_media_items[0]['file']->filemime;

                $media_content = '<!-- Portfolio thumb 1 -->
                    <div class="four columns medium-six columns small-twelve columns"><div class="portfolio-thumb">';
                if($filemime == 'audio/soundcloud') {
                    $media_content .= '<div id="soundcloud-popup" style="display:none;">'.$fields['field_multimedia']->content.'</div>';
                    $media_content .= '<a class="popup-soundcloud" href="'.$base_url.'/ajax_soundcloud_popup">';
                } else {
                    $media_content .= '<a class="popup" href="'.$file_url.'">';
                }
                $media_content .= '<img alt="'.$thumbnail_name.'" src="'.$thumbnail_url.'">
                        <i class="fontello icon-music"></i>
                        <b>'.$fields['title']->content.'</b>
                        <em>Soundcloud Popup</em>
                    </a>
                </div></div>';
            }
        } else {
            $type_arr = array();
            $media_content .= '<!-- Portfolio thumb 1 -->
                    <div class="four columns medium-six columns small-twelve columns"><div class="portfolio-thumb">';
            $count = count($multimedia);
            for($i=0;$i<$count;$i++) {
                $raw_value = $multimedia[$i]['raw']['value'];
                $field_media_items = $multimedia[$i]['rendered']['entity']['field_collection_item'][$raw_value]['field_media']['#items'];
                $type_arr[] = $field_media_items[0]['file']->type;
                $file_url = file_create_url($field_media_items[0]['file']->uri);
                if($i < $count-1) {
                    $media_content .= '<a class="popup-gallery" href="'.$file_url.'"></a>';
                } else {
                    $media_content .= '<a class="popup-gallery" href="'.$file_url.'">';
                }
            }
            $media_content .= '<img alt="'.$thumbnail_name.'" src="'.$thumbnail_url.'">';
            $media_content .= '<i class="fontello icon-picture"></i>
                         <b>'.$fields['title']->content.'</b>
                        <em>Slider Popup</em></a>';

            $media_content .= '</div></div>';
        }
}
?>
<?php print $media_content;?>
