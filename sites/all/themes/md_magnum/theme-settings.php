<?php
/**
 * @file
 * Theme setting callbacks for the Media Star theme.
 */
global $base_url;
drupal_add_js(drupal_get_path('theme', 'md_magnum') . '/js/lib/modernizr.custom.js');
$inline_js = 'var polyfilter_scriptpath = "'.drupal_get_path('theme', 'md_magnum').'/js/lib/";';
drupal_add_js($inline_js,'inline');
drupal_add_css(drupal_get_path('theme', 'md_magnum') . '/css/theme-settings.css', array('group' => CSS_THEME));
drupal_add_css(drupal_get_path('theme', 'md_magnum') . '/js/lib/colorpicker/css/colorpicker.css', array('group' => CSS_THEME));
drupal_add_css(drupal_get_path('theme', 'md_magnum') . '/js/lib/css/modal-default.css', array('group' => CSS_THEME));
drupal_add_css(drupal_get_path('theme', 'md_magnum') . '/js/lib/css/modal-component.css', array('group' => CSS_THEME));
if(module_exists('icon') && module_exists('fontello')) {
    $icon_bundles = icon_bundles();
    foreach($icon_bundles as $key => $value) {
        if($value['status'] == 1) {
            fontello_process_attached($key);
        }
    }
}
drupal_add_js(drupal_get_path('theme', 'md_magnum') . '/js/lib/jquery.cookie.js');

drupal_add_library('system', 'ui.widget');
drupal_add_library('system', 'ui.mouse');
drupal_add_library('system', 'ui.slider');
drupal_add_library('system', 'ui.tabs');
drupal_add_library('system', 'ui.dialog');
drupal_add_library('system', 'ui.draggable');
drupal_add_library('system', 'ui.sortable');
drupal_add_library('system', 'ui.slider');


drupal_add_js(drupal_get_path('theme', 'md_magnum') . '/js/lib/colorpicker/js/colorpicker.js');
drupal_add_js(drupal_get_path('theme', 'md_magnum') . '/js/lib/jquery.leanModal.min.js');
drupal_add_js(drupal_get_path('theme', 'md_magnum') . '/js/lib/jquery.choosefont.js');
drupal_add_js(drupal_get_path('theme', 'md_magnum') . '/js/lib/jquery.mousewheel.js');
drupal_add_js(drupal_get_path('theme', 'md_magnum') . '/js/lib/jquery.jstepper.min.js');
drupal_add_js(drupal_get_path('theme', 'md_magnum') . '/js/lib/classie.js');
drupal_add_js(drupal_get_path('theme', 'md_magnum') . '/js/lib/modalEffects.js');
drupal_add_js(drupal_get_path('theme', 'md_magnum') . '/js/lib/cssParser.js');
drupal_add_js(drupal_get_path('theme', 'md_magnum') . '/js/lib/css-filters-polyfill.js');
drupal_add_js(drupal_get_path('theme', 'md_magnum') . '/js/lib/popup-content.js');

drupal_add_js(drupal_get_path('theme', 'md_magnum') . '/js/lib/theme-settings.js');

require_once DRUPAL_ROOT . '/' . drupal_get_path('theme', 'md_magnum') . '/inc/theme-settings-general.inc';
require_once DRUPAL_ROOT . '/' . drupal_get_path('theme', 'md_magnum') . '/inc/theme-settings-design.inc';
require_once DRUPAL_ROOT . '/' . drupal_get_path('theme', 'md_magnum') . '/inc/theme-settings-text.inc';
require_once DRUPAL_ROOT . '/' . drupal_get_path('theme', 'md_magnum') . '/inc/theme-settings-pages.inc';
require_once DRUPAL_ROOT . '/' . drupal_get_path('theme', 'md_magnum') . '/inc/theme-settings-code.inc';
require_once DRUPAL_ROOT . '/' . drupal_get_path('theme', 'md_magnum') . '/inc/theme-settings-config.inc';

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * @param $form
 *   The form.
 * @param $form_state
 *   The form state.
 */

function md_magnum_form_system_theme_settings_alter(&$form, &$form_state, $form_id = NULL, $no_js_use = FALSE) {
    if(isset($form_id)){
      return;
    }
    $form['md_magnum_settings']['html_header'] = array(
        '#markup' => '
<!--<div class="md-links">
<a href="#" target="_blank">Project Page</a> -
<a href="#" target="_blank">Theme Documentation</a> -
<a href="#" target="_blank">Support Forum</a>
</div> -->
<div class="md-wrap">
  <div id="md-tabs">
		<div class="md-tabs-head"><div class="md-tabs-headcontent">
      <ul class="clearfix">
        <li class="tab-item first clearfix" id="tab-general-settings"> <a class="tab-link" href="#md-general-settings">
          <span class="tab-text">General Settings</span>
          </a> </li>
        <li class="tab-item clearfix" id="tab-design"> <a class="tab-link" href="#md-design">
          <span class="tab-text">Design</span>
          </a> </li>
        <li class="tab-item clearfix" id="tab-text-typography"> <a class="tab-link" href="#md-text-typography">
          <span class="tab-text">Text/Typography</span>
          </a> </li>
        <li class="tab-item clearfix" id="tab-custom-code"> <a class="tab-link" href="#md-custom-code">
          <span class="tab-text">Custom code</span>
          </a> </li>
          <li class="tab-item clearfix" id="tab-config"> <a class="tab-link" href="#md-config">
          <span class="tab-text">Bacxup and Restore</span>
          </a>
        </li>
      </ul>
    </div></div><!-- /.md-tabs-head -->',
        '#weight' => -99,
    );


    md_magnum_theme_settings_general($form, $form_state);

    $fontarray = array(
        '0'   => t('Default'),
        '1'   => t('Arial'),
        '2'   => t('Verdana'),
        '3'   => t('Trebuchet MS'),
        '4'   => t('Georgia'),
        '5'   => t('Times New Roman'),
        '6'   => t('Tahoma'),
    );
    $fontvars = array(
        '0'	=> array(
            'CSS' 		=>	'',
            'Weight'	=>	'n4',
        ),
        '1'	=> array(
            'CSS' 		=>	'Arial, sans-serif',
            'Weight'	=>	'n4, n7, i4, i7',
        ),
        '2'	=> array(
            'CSS' 		=>	'Verdana, Geneva, sans-serif',
            'Weight'	=>	'n4, n7, i4, i7',
        ),
        '3'	=> array(
            'CSS' 		=>	'Trebuchet MS, Tahoma, sans-serif',
            'Weight'	=>	'n4, n7, i4, i7',
        ),
        '4'	=> array(
            'CSS' 		=>	'Georgia, serif',
            'Weight'	=>	'n4, n7, i4, i7',
        ),
        '5'	=> array(
            'CSS' 		=>	'Times New Roman, serif',
            'Weight'	=>	'n4, n7, i4, i7',
        ),
        '6'	=> array(
            'CSS' 		=>	'Tahoma, Geneva, Verdana, sans-serif',
            'Weight'	=>	'n4, n7, i4, i7',
        ),
    );
    // Load font styles
    $fonts = load_font_configure();
    drupal_add_js(array('font_array' => $fonts[0]), 'setting');
    drupal_add_js(array('font_vars' => $fonts[1]), 'setting');
    // add for fonts END

    md_magnum_theme_settings_design($form, $form_state);
    md_magnum_theme_settings_text($form, $form_state);
    md_magnum_theme_settings_code($form, $form_state);
    md_magnum_theme_settings_config($form, $form_state);

    $form['md_magnum_settings']['html_footer'] = array(
        '#markup' => '
	</div><!-- /#md-tabs -->
</div><!-- /.md-wrap -->',
        '#weight' => 99,
    );
    $form['reset']      = array(
        '#type'         => 'submit',
        '#value'        => t('Reset Settings'),
        '#submit'       => array('md_magnum_reset_settings_submit'),
        '#weight'       => '1000',
    );
   $form['#submit'][] = 'md_magnum_save_settings';
   $form['#validate'][] = 'md_magnum_validate_theme_settings';
}
/**
 * Custom validation for md_magnum theme setting
 */
function md_magnum_validate_theme_settings($form, &$form_state) {
/*    // Header video link
    $header_bg_type = $form_state['input']['header_background_type'];
    $ft_bg_type = $form_state['input']['footer_background'];
    $nf_bg_type = $form_state['input']['nf_background'];
    if($header_bg_type == 'video') {
        $hd_video_link = $form_state['input']['header_video_link'];
        if(empty($hd_video_link)) {
            form_set_error('header_video_link','Header Video Background Link cannot be null');
        }
    }
    if($ft_bg_type == 'video') {
        $ft_video_link = $form_state['input']['ft_video_link'];
        if(empty($form_state['input']['ft_video_link'])) {
            form_set_error('ft_video_link','Footer Video Background Link cannot be null');
        }
    }
    if($nf_bg_type == 'video') {
        $nf_video_link = $form_state['input']['nf_video_link'];
        if(empty($nf_video_link)) {
            form_set_error('nf_video_link','404 Page Video Background Link cannot be null');
        }
    }
    for($i=1;$i<=3;$i++) {
        $pr_bg_type = $form_state['input']['parallax_'.$i.'_background_type'];
        if($pr_bg_type == 'video') {
            $pr_video_link = $form_state['input']['pr'.$i.'_video_link'];
            if(empty($pr_video_link)) {
                form_set_error('pr'.$i.'_video_link','Parallax '.$i.' Video Background Link cannot be null');
            }
        }
    }*/
}
/**
 * Analys goole link to get font information
 */
function _md_magnum_process_google_web_font($fonts) {
    if (strpos($fonts, '@import url(') !== FALSE) {
        preg_match("/http:\/\/\s?[\'|\"]?(.+)[\'|\"]?\s?(\)|\')/Uix", $fonts, $ggwflink);
    }

    preg_match('/([^\?]+)(\?family=)?([^&\']+)/i', $fonts, $matches);
    $gfonts = explode("|", $matches[3]);

    for ($i = 0; $i < count($gfonts); $i++) {
        $gfontsdetail = explode(":", $gfonts[$i]);
        $gfontname = str_replace("+", " ", $gfontsdetail['0']);
        $fontarray[] = $gfontname;
        if (array_key_exists('1', $gfontsdetail)) {
            $tmpft = explode(",", $gfontsdetail['1']);
            $gfontweigth[$i] = "";
            for ($j = 0; $j < count($tmpft); $j++) {
                if (preg_match("/italic/i", $tmpft[$j])) {
                    $gfontstyle = "i";
                } else {
                    $gfontstyle = "n";
                }
                $tmpw = str_replace("italic", "", $tmpft[$j]);
                $seperator = ",";

                if ($j == (count($tmpft) - 1)) {
                    $seperator = "";
                }

                if ($tmpw) {
                    $gfontweigth[$i] .= $gfontstyle . str_replace("00", "", $tmpw) . $seperator;
                } else {
                    $gfontweigth[$i] .= "n4" . $seperator;
                }
            }
        } else {
            $gfontweigth[$i] = "n4";
        }
        $fontvars[] = array(
            'CSS' => '"' . $gfontname . '"',
            'Weight' => $gfontweigth[$i],
        );
    }

    return array($fontarray, $fontvars);
}
/**
 * Get fonts information from type-kit id
 */
function _md_magnum_process_typekit_font($typekit_id) {
    $tk_url = 'http://typekit.com/api/v1/json/kits/' . $typekit_id . '/published';
    $typekit = json_decode(file_get_contents($tk_url), true);
    for ($i = 0; $i < count($typekit['kit']['families']); $i++) {
        $fontarray[] = $typekit['kit']['families'][$i]['name'];
        $fontweight = "";
        for ($j = 0; $j < count($typekit['kit']['families'][$i]['variations']); $j++) {
            if (($j + 1) == count($typekit['kit']['families'][$i]['variations'])) {
                $fontweight .= $typekit['kit']['families'][$i]['variations'][$j];
            } else {
                $fontweight .= $typekit['kit']['families'][$i]['variations'][$j] . ',';
            }
        }
        $fontvars[] = array(
            'CSS' => $typekit['kit']['families'][$i]['css_stack'],
            'Weight' => $fontweight,
        );
    }

    return array($fontarray, $fontvars);
}
/**
 * Load font configure
 */
function load_font_configure() {
    $theme_default = variable_get('theme_default', 'Bartik');
    $fontarray = array(
        t('Default'),
        t('Arial'),
        t('Verdana'),
        t('Trebuchet MS'),
        t('Georgia'),
        t('Times New Roman'),
        t('Tahoma'),
    );

    $fontvars = array(
        array('CSS' => '', 'Weight' => 'n4'),
        array('CSS' => 'Arial, sans-serif', 'Weight' => 'n4, n7, i4, i7'),
        array('CSS' => 'Verdana, Geneva, sans-serif', 'Weight' => 'n4, n7, i4, i7'),
        array('CSS' => 'Trebuchet MS, Tahoma, sans-serif', 'Weight' => 'n4, n7, i4, i7'),
        array('CSS' => 'Georgia, serif', 'Weight' => 'n4, n7, i4, i7'),
        array('CSS' => 'Times New Roman, serif', 'Weight' => 'n4, n7, i4, i7'),
        array('CSS' => 'Tahoma, Geneva, Verdana, sans-serif', 'Weight' => 'n4, n7, i4, i7'),
    );
    $google_font = theme_get_setting('googlewebfonts','md_magnum');
    if ($google_font != '') {
        $result = _md_magnum_process_google_web_font($google_font);
        add_font_style($result, $fontarray, $fontvars);
    }
    $typekit = theme_get_setting('typekit_id','md_magnum');;

    if ($typekit != '') {
        $result = _md_magnum_process_typekit_font($typekit);
        add_font_style($result, $fontarray, $fontvars);
    }

    return array($fontarray, $fontvars);
}

function add_font_style($results, &$font_array, &$font_vars) {
    if (is_array($results)) {
        foreach ($results[0] as $id => $font_name) {
            $key = array_search($font_name, $font_array);
            if ($key === FALSE) {
                $font_array[] = $font_name;
                $font_vars[] = $results[1][$id];
            } else {
                $font_vars[$key] = $results[1][$id];
            }
        }
    }
}


/**
 * Final submit handler.
 *
 * Reports what values were finally set.
 */

function md_magnum_save_settings($form, &$form_state) {
    $form_input = $form_state['input'];
    $form_state['values']['hd_vd_ct_2_icon'] = array();
    $form_state['values']['hd_image_slide'] = array();
    $form_state['values']['ft_image_slide'] = array();
    $form_state['values']['nf_image_slide'] = array();
    $form_state['values']['hd_slide_ct_text_icon'] = array();
    $form_state['values']['hd_slide_ct_text'] = array();
    $form_state['values']['nf_slide'] = array();
    $form_state['values']['ft_sc'] = array();
    for($i=1;$i<=3;$i++){
        // Parallax Image Slide
        $pr_image_slide = "/pr_".$i."_image_slide_order/i";
        $form_state['values']['pr_'.$i.'_image_slide'] = array();
        // Parallax Content Text
        $pr_ct_text_match = "/pr_".$i."_ct_text_order/i";
        $form_state['values']['pr_'.$i.'_ct_text'] = array();
        //loop through the data
        foreach($form_input as $key => $value){
            if(preg_match($pr_ct_text_match, $key)) {
                $explode_skills = explode("|",$value);
                foreach($explode_skills as $key2 => $value2) {
                    $new_key = str_replace("-","_",$value2);
                    $new_explode = explode("_",$new_key);
                    end($new_explode);
                    $number = current($new_explode);
                    if($new_key != null) {
                        $form_state['values']['pr_'.$i.'_ct_text'][$new_key]['title'] = $form_input['pr_'.$i.'_ct_text_title_'.$number] ? $form_input['pr_'.$i.'_ct_text_title_'.$number] : '';
                        $form_state['values']['pr_'.$i.'_ct_text'][$new_key]['sub_title'] = $form_input['pr_'.$i.'_ct_text_sub_title_'.$number] ? $form_input['pr_'.$i.'_ct_text_sub_title_'.$number] : '';
                    }
                }
            }
            if(preg_match($pr_image_slide,$key)) {
                $explode = explode("|",$value);
                foreach($explode as $key2 => $value2) {
                    $new_key = str_replace("-","_",$value2);
                    $new_explode = explode("_",$new_key);
                    end($new_explode);
                    $number = current($new_explode);
                    if($new_key != null) {
                        $form_state['values'] = saveImage('pr_'.$i.'_image_slide_path_'.$number,'pr_'.$i.'_image_slide_upload_'.$number,$form_state['values']);
                        $form_state['values']['pr_'.$i.'_image_slide'][$new_key]['image'] = $form_state['values']['pr_'.$i.'_image_slide_path_'.$number];
                    }
                }
            }
        }
    }
    foreach($form_state['input'] as $key => $value) {
        // Header Video Content 2 Icon
        $hd_vd_ct_2_icon_match = "/hd_vd_ct_2_icon_order/i";
        // Header Image Slide
        $hd_image_slide_match = "/hd_image_slide_order/i";
        // Header Slide Text Icon
        $hd_slide_ct_text_icon_match = "/hd_slide_ct_text_icon_order/i";
        // Header Slide Text
        $hd_slide_ct_text_match = "/hd_slide_ct_text_order/i";
        // Footer Image Slide
        $ft_image_slide_match = "/ft_image_slide_order/i";
        // Footer Social Icon
        $ft_sc_match = "/ft_sc_order/i";
        // 404 Image Slide
        $nf_image_slide_match = "/nf_image_slide_order/i";


        if(preg_match($hd_slide_ct_text_icon_match,$key)) {
            $explode = explode("|",$value);
            if($explode != null){
                foreach($explode as $key2 => $value2) {
                    $new_key = str_replace("-","_",$value2);
                    $new_explode = explode("_",$new_key);
                    end($new_explode);
                    $number = current($new_explode);
                    if($new_key != null) {
                        $form_state['values']['hd_slide_ct_text_icon'][$new_key]['link'] = $form_input['hd_slide_ct_text_icon_link_'.$number] ? $form_input['hd_slide_ct_text_icon_link_'.$number] : '';
                        $form_state['values']['hd_slide_ct_text_icon'][$new_key]['title'] = $form_input['hd_slide_ct_text_icon_title_'.$number] ? $form_input['hd_slide_ct_text_icon_title_'.$number] : '';
                        $form_state['values']['hd_slide_ct_text_icon'][$new_key]['sub_title'] = $form_input['hd_slide_ct_text_icon_sub_title_'.$number] ? $form_input['hd_slide_ct_text_icon_sub_title_'.$number] : '';
                        $icon_input = $form_input['hd_slide_ct_text_icon_icon_'.$number]['icon'];
                        if($icon_input != null){
                            $hd_slide_ct_text_icon_explode = explode("|",$icon_input);
                            $form_state['values']['hd_slide_ct_text_icon'][$new_key]['icon']['bundle'] = $hd_slide_ct_text_icon_explode[0];
                            $form_state['values']['hd_slide_ct_text_icon'][$new_key]['icon']['icon'] = $hd_slide_ct_text_icon_explode[1];
                        }
                    }
                }
            }
        }
        if(preg_match($hd_slide_ct_text_match,$key)) {
            $explode = explode("|",$value);
            if($explode != null){
                foreach($explode as $key2 => $value2) {
                    $new_key = str_replace("-","_",$value2);
                    $new_explode = explode("_",$new_key);
                    end($new_explode);
                    $number = current($new_explode);
                    if($new_key != null) {
                        $form_state['values']['hd_slide_ct_text'][$new_key]['title'] = $form_input['hd_slide_ct_text_title_'.$number] ? $form_input['hd_slide_ct_text_title_'.$number] : '';
                        $form_state['values']['hd_slide_ct_text'][$new_key]['sub_title'] = $form_input['hd_slide_ct_text_sub_title_'.$number] ? $form_input['hd_slide_ct_text_sub_title_'.$number] : '';
                        $form_state['values']['hd_slide_ct_text'][$new_key]['button_text'] = $form_input['hd_slide_ct_text_button_text_'.$number] ? $form_input['hd_slide_ct_text_button_text_'.$number] : '';
                        $form_state['values']['hd_slide_ct_text'][$new_key]['button_link'] = $form_input['hd_slide_ct_text_button_link_'.$number] ? $form_input['hd_slide_ct_text_button_link_'.$number] : '';
                    }
                }
            }
        }
        if(preg_match($ft_sc_match,$key)) {
            $explode = explode("|",$value);
            foreach($explode as $key2 => $value2) {
                $new_key = str_replace("-","_",$value2);
                $new_explode = explode("_",$new_key);
                end($new_explode);
                $number = current($new_explode);
                if($new_key != null) {
                    $icon_input = $form_input['ft_sc_icon_'.$number]['icon'];
                    if($icon_input != null){
                        $ft_sc_icon_explode = explode("|",$icon_input);
                        $form_state['values']['ft_sc'][$new_key]['icon']['bundle'] = $ft_sc_icon_explode[0];
                        $form_state['values']['ft_sc'][$new_key]['icon']['icon'] = $ft_sc_icon_explode[1];
                    }
                    $form_state['values']['ft_sc'][$new_key]['link'] = $form_input['ft_sc_link_'.$number] ? $form_input['ft_sc_link_'.$number] : '';

                }
            }
        }
        if(preg_match($hd_image_slide_match,$key)) {
            $explode = explode("|",$value);
            foreach($explode as $key2 => $value2) {
                $new_key = str_replace("-","_",$value2);
                $new_explode = explode("_",$new_key);
                end($new_explode);
                $number = current($new_explode);
                if($new_key != null) {
                    $form_state['values'] = saveImage('hd_image_slide_path_'.$number,'hd_image_slide_upload_'.$number,$form_state['values']);
                    $form_state['values']['hd_image_slide'][$new_key]['image'] = $form_state['values']['hd_image_slide_path_'.$number];
                }
            }
        }
        if(preg_match($ft_image_slide_match,$key)) {
            $explode = explode("|",$value);
            foreach($explode as $key2 => $value2) {
                $new_key = str_replace("-","_",$value2);
                $new_explode = explode("_",$new_key);
                end($new_explode);
                $number = current($new_explode);
                if($new_key != null) {
                    $form_state['values'] = saveImage('ft_image_slide_path_'.$number,'ft_image_slide_upload_'.$number,$form_state['values']);
                    $form_state['values']['ft_image_slide'][$new_key]['image'] = $form_state['values']['ft_image_slide_path_'.$number];
                }
            }
        }
        if(preg_match($nf_image_slide_match,$key)) {
            $explode = explode("|",$value);
            foreach($explode as $key2 => $value2) {
                $new_key = str_replace("-","_",$value2);
                $new_explode = explode("_",$new_key);
                end($new_explode);
                $number = current($new_explode);
                if($new_key != null) {
                    $form_state['values'] = saveImage('nf_image_slide_path_'.$number,'nf_image_slide_upload_'.$number,$form_state['values']);
                    $form_state['values']['nf_image_slide'][$new_key]['image'] = $form_state['values']['nf_image_slide_path_'.$number];
                }
            }
        }

        if(preg_match($hd_vd_ct_2_icon_match,$key)) {
            $explode = explode("|",$value);
            foreach($explode as $key2 => $value2) {
                $new_key = str_replace("-","_",$value2);
                $new_explode = explode("_",$new_key);
                end($new_explode);
                $number = current($new_explode);
                if($new_key != null) {
                    $form_state['values']['hd_vd_ct_2_icon'][$new_key]['link'] = $form_input['hd_vd_ct_2_icon_link_'.$number] ? $form_input['hd_vd_ct_2_icon_link_'.$number] : '';
                    $form_state['values']['hd_vd_ct_2_icon'][$new_key]['title'] = $form_input['hd_vd_ct_2_icon_title_'.$number] ? $form_input['hd_vd_ct_2_icon_title_'.$number] : '';
                    $form_state['values']['hd_vd_ct_2_icon'][$new_key]['sub_title'] = $form_input['hd_vd_ct_2_icon_sub_title_'.$number] ? $form_input['hd_vd_ct_2_icon_sub_title_'.$number] : '';
                    $icon_input = $form_input['hd_vd_ct_2_icon_icon_'.$number]['icon'];
                    if($icon_input != null){
                        $hd_vd_ct_2_icon_explode = explode("|",$icon_input);
                        $form_state['values']['hd_vd_ct_2_icon'][$new_key]['icon']['bundle'] = $hd_vd_ct_2_icon_explode[0];
                        $form_state['values']['hd_vd_ct_2_icon'][$new_key]['icon']['icon'] = $hd_vd_ct_2_icon_explode[1];
                    }
                }
            }
        }
    }
    $form_state['values'] = saveImage('preloader_logo_path','preloader_logo_upload',$form_state['values']);
    $form_state['values'] = saveImage('header_video_image_fallback','header_video_image_fallback_upload',$form_state['values']);
    $form_state['values'] = saveImage('nf_video_image_fallback','nf_video_image_fallback_upload',$form_state['values']);
    $form_state['values'] = saveImage('team_background_path','team_background_upload',$form_state['values']);
    $form_state['values'] = saveImage('logo_normal_path','logo_normal_upload',$form_state['values']);
    $form_state['values'] = saveImage('logo_retina_path','logo_retina_upload',$form_state['values']);
    $form_state['values'] = saveImage('fvicon_path','fvicon_upload',$form_state['values']);



    $form_state['values']['logo_path'] = $form_state['values']['logo_normal_path'];
    $form_state['values']['favicon_path'] = $form_state['values']['fvicon_path'];
    if($form_state['values']['default_logo'] == 1){
        $form_state['values']['logo_path'] = '';
        $form_state['values']['logo_normal_path'] = '';
        $form_state['values']['logo_retina_path'] = '';
    }
    if($form_state['values']['default_favicon'] == 1){
        $form_state['values']['favicon_path'] = '';
        $form_state['values']['fvicon_path'] = '';
    }

    //cache_clear_all();
}
function saveImage($path, $upload, $form_state_value) {
    if ($image_file = file_save_upload($upload)) {
        $parts = pathinfo($image_file->filename);
        $destination = 'public://' . $parts['basename'];
        $image_file->status = FILE_STATUS_PERMANENT;
        if (file_copy($image_file, $destination, FILE_EXISTS_REPLACE)) {
            $_POST[$path] = $form_state_value[$path] = $parts['basename'];
        }
    }
    if (isset($form_state_value[$path])) {
        $file_path = $form_state_value[$path];

        $file_scheme = file_uri_scheme($path);
        if($file_scheme == 'http' || $file_scheme == 'https'){
            $newimagename = basename(rawurldecode($file_path));
            $external_file = file_get_contents(rawurldecode($file_path));
            file_save_data($external_file, 'public://'.$newimagename.'',$replace = FILE_EXISTS_REPLACE);
            $form_state_value[$path] = $newimagename;
        }
    }
    return $form_state_value;
}
/**
 * @param $form
 * @param $form_state
 * Reset all theme settings
 */
function md_magnum_reset_settings_submit($form, &$form_state){
    $theme_settings = variable_get('theme_md_magnum_settings');
    $default_settings = _md_magnum_theme_default_settings($theme_settings);
    variable_set('theme_md_magnum_settings',null);
    variable_set('theme_md_magnum_settings',$default_settings);
    drupal_set_message('All settings reset to default');
    cache_clear_all();
}
/**
 * Backup Theme Settings
 */
function md_magnum_backup_theme_settings() {
    $theme_settings = variable_get('theme_md_magnum_settings');
    $current_time = time();
    $cv_datetime = date("Y-m-d",$current_time);
    $backup_file = serialize(base64_encode(drupal_json_encode($theme_settings)));
    $bu_folder = 'public://md_magnum_backup';
    if(file_prepare_directory($bu_folder) === false) {
        drupal_mkdir($bu_folder);
    }
    if (file_unmanaged_save_data($backup_file, $bu_folder . '/backup-'.$cv_datetime.'-'.$current_time.'.txt', FILE_EXISTS_REPLACE) === FALSE) {
        drupal_set_message(t("Could not create backup file."));
        return;
    } else {
        drupal_set_message(t("Backup Theme Settings Successful!"));
    }
}
/**
 * Restore Theme settings
 */
function md_magnum_restore_theme_settings($form, &$form_state) {
    variable_set('theme_md_magnum_settings',array());
    if ($restore_file = file_save_upload('restore_file_upload')) {
        $file_content = file_get_contents($restore_file->uri);
        $restore_settings = drupal_json_decode(base64_decode(unserialize($file_content)));
        variable_set('theme_md_magnum_settings',$restore_settings);
        cache_clear_all();
        drupal_set_message(t('All your theme settings have been restored'));
    }
    elseif($restore_file_path = $form_state['values']['restore_file_path']) {
        $restore_file_scheme = file_uri_scheme($restore_file_path);
        if($restore_file_scheme == 'http' || $restore_file_scheme == 'https') {
            $restore_file_url = rawurldecode($restore_file_path);
            $restore_file_content = file_get_contents($restore_file_url);
            $restore_settings = drupal_json_decode(base64_decode(unserialize($restore_file_content)));
            variable_set('theme_md_magnum_settings',$restore_settings);
            cache_clear_all();
            drupal_set_message(t('All your theme settings have been restored'));
        } else {
            $restore_file_content = file_get_contents($restore_file_path);
            $restore_settings = drupal_json_decode(base64_decode(unserialize($restore_file_content)));
            variable_set('theme_md_magnum_settings',$restore_settings);
            cache_clear_all();
            drupal_set_message(t('All your theme settings have been restored'));
        }
    }
}

/**
 * Default theme settings
 */
function _md_magnum_theme_default_settings ($theme_settings) {
    $default_settings = array();
    foreach ($theme_settings as $key => $setting) {
        $default_settings[$key] = null;
    }
    $default_settings['toggle_logo'] = 1;
    $default_settings['toggle_name'] = 1;
    $default_settings['toggle_slogan'] = 1;
    $default_settings['toggle_node_user_picture'] = 1;
    $default_settings['toggle_comment_user_picture'] = 1;
    $default_settings['toggle_comment_user_verification'] = 1;
    $default_settings['toggle_favicon'] = 1;
    $default_settings['toggle_main_menu'] = 1;
    $default_settings['toggle_secondary_menu'] = 1;
    $default_settings['default_logo'] = 1;
    $default_settings['default_favicon'] = 1;
    $default_settings['css3_textarea'] = 0;
    $default_settings['webclip_precomp'] = 1;
    $default_settings['skins'] = 'default';
    $default_settings['parallax_1_enabled'] = 0;
    $default_settings['parallax_2_enabled'] = 1;
    $default_settings['parallax_3_enabled'] = 1;
    $default_settings['typo_heading_style_enable'] = 0;
    $default_settings['header_size'] = 'full';
    $default_settings['header_background_type'] = 'video';
    $default_settings['header_video_play'] = 0;
    $default_settings['header_video_link'] = 'http://www.youtube.com/watch?v=kn-1D5z3-Cs';
    $default_settings['header_video_content_display'] = '1';
    $default_settings['parallax_1_background_type'] = 'global';
    $default_settings['parallax_2_background_type'] = 'color';
    $default_settings['pr_2_bg_color'] = '333333';
    $default_settings['parallax_3_background_type'] = 'custom';
    $default_settings['footer_background'] = 'color';
    $default_settings['ft_bg_color'] = 'f0f0f0';
    $default_settings['footer_content_display'] = '1';
    $default_settings['social_link_1'] = 'http://facebook.com';
    $default_settings['nf_background'] = 'custom';
    $default_settings['pr1_big_text_1'] = 'Magnum is made to tell a story';
    $default_settings['pr1_sub_text_1'] = '— Cr. Lee, Freelance Developer —';
    $default_settings['pr2_big_text_1'] = 'Magnum is made to tell a story';
    $default_settings['pr2_sub_text_1'] = '— Cr. Lee, Freelance Developer —';
    $default_settings['pr3_big_text_1'] = 'Magnum is made to tell a story';
    $default_settings['pr3_sub_text_1'] = '— Cr. Lee, Freelance Developer —';
    $default_settings['preloader_delay_time'] = '350';
    $default_settings['preloader_bg_type'] = 'skin';
    $default_settings['preloader_type'] = '1';
    $default_settings['preloader_enable_logo'] = 1;
    $default_settings['menu_sticky'] = 1;
    $default_settings['menu_bg_color'] = '1A1A1A';
    $default_settings['menu_link_color'] = '7A7A7A';
    $default_settings['menu_link_hover_color'] = 'FFFFFF';
    $default_settings['nf_text'] = 'Oops! I couldnt find that one.<br>Click the button below to go back home.';

    $default_settings['nodetitle_enable'] = 0;
    $default_settings['typo_view_title_enable'] = 0;
    $default_settings['maintenance_message'] = '<p><span>Our awesome website is</span> <br> Under construction </p>';
    $default_settings['footer_text'] = 'Magnum™ design by
<a class="underline" target="blank" href="http://themeforest.net/user/Pixel-Stuff">PixelStuff</a>
- Drupal theme by
<a class="underline" target="blank" href="http://themeforest.net/user/megadrupal">MegaDrupal</a>
<br>
— Made with
<i class="fontello icon-heart text-color"></i>
on The Moon —';

    return $default_settings;
}
function icon_default_markup() {
    $icon_bundles = icon_bundles();
}
