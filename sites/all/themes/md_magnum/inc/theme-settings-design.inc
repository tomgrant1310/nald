<?php

/**
 * @file
 * Theme settings .
 */

function md_magnum_theme_settings_design(&$form, &$form_state) {
    global $base_url;
    $options = array();
    foreach (icon_bundles() as $bundle_name => $bundle) {
        if (!$bundle['status']) {
            continue;
        }
        foreach ($bundle['icons'] as $icon_key => $icon_value) {
            $icon_name = is_string($icon_key) ? $icon_key : $icon_value;
            if (is_array($icon_value) && isset($icon_value['name'])) {
                $icon_name = $icon_value['name'];
            }
            $icon_title = is_string($icon_value) ? $icon_value : $icon_name;
            if (is_array($icon_value) && isset($icon_value['title'])) {
                $icon_title = $icon_value['title'];
            }
            $options[$bundle['title']][$bundle['name'] . '|' . $icon_name] = $icon_title;
        }
    $icon_default_value = $options;
    }
    $icon_mark_up = '';
    $icon_fake_markup = '<ul class="list-icon">';
    foreach($icon_default_value as $key => $value) {
        $icon_mark_up .= '<option selected="selected" value="">- No Icon -</option><optgroup label="'.$key.'">';
        foreach ($icon_default_value[$key] as $key2 => $value2) {
            $fake_icon_explode = explode("|",$key2);
            $icon_fake_markup .= '<li><a href="javascript:;" class="fake-icon" icon-name="'.$fake_icon_explode[1].'" data-icon="'.$key2.'"><i class="'.$fake_icon_explode[0].' '.$fake_icon_explode[1].'"></i></a></li>';
            $icon_mark_up .= '<option value="'.$key2.'">'.$value2.'</option>';
        }
        $icon_mark_up .= '</optgroup>';
    }
    $icon_fake_markup .= '</ul>';
    drupal_add_js(array('iconMarkUp' => $icon_mark_up),'setting');
    drupal_add_js(array('iconFakeMarkUp' => $icon_fake_markup),'setting');

	$form['md_magnum_settings']['design'] = array(
		'#type' 					=> 'fieldset',
		'#weight' 				=> -4,
		'#prefix'  				=> '<div id="md-design" class="md-tabcontent clearfix">',
		'#suffix'        => '</div><!-- / #md-design -->',
	);
	
	$form['md_magnum_settings']['design']['design_htmllist'] = array(
		'#markup' 				=> '<div class="md-listleft">
				<ul>
				    <li><a href="#ds-general">Skins</a></li>
				    <li><a href="#ds-preloader">Pre-Loader</a></li>
				    <li><a href="#ds-menu">Menu</a></li>
				    <li><a href="#ds-header">Header</a></li>
				    <li><a href="#ds-introduction">Introduction</a></li>
					<li><a href="#ds-parallax">Parallax</a></li>
					<li><a href="#ds-team">Team</a></li>
					<li><a href="#ds-footer">Footer</a></li>
                    <li><a href="#ds-nf">404 Page</a></li>
				</ul>
			</div><div class="md-listcontent">',
		'#weight' 				=> -15,
	);
	$form['md_magnum_settings']['design']['design_htmllistclose'] = array(
		'#markup' 				=> '</div><!-- /.md-listleft -->',
		'#weight' 				=> 15,
	);
    $form['md_magnum_settings']['design']['design_general'] = array(
        '#type' 					=> 'fieldset',
        '#weight' 				=> -5,
        '#prefix'  				=> '<div id="ds-general" class="md-tabcontent clearfix">',
        '#suffix'        => '</div><!-- / #ds-general -->',
    );
    // Site skins
    $form['md_magnum_settings']['design']['design_general']['skins'] = array(
        '#type'          => 'select',
        '#title'         => t('Choose skin'),
        '#default_value' => theme_get_setting('skins'),
        '#options'       => array(
            'default'   => t('Default (Brown)'),
            'yellow'    => t('Yellow'),
            'green' 	=> t('Green'),
            'ruby' 	    => t('Ruby'),
            'teal' 	    => t('Teal'),
            'blue' 	    => t('Blue'),
            'orange' 	    => t('Orange'),
            'purple' 	=> t('Purple'),
        ),
        '#prefix' => '<div id="design-skins" class="clearfix">',
        '#suffix' => '</div>',
    );
    /* 2.Pre-loader
    ====================================================================================*/
    $form['md_magnum_settings']['design']['design_preloader'] = array(
        '#type' 					=> 'fieldset',
        '#weight' 				=> -5,
        '#prefix'  				=> '<div id="ds-preloader" class="md-tabcontent clearfix"><h3>Pre-loader Configuration</h3>',
        '#suffix'        => '</div><!-- / #ds-general -->',
    );
    $form['md_magnum_settings']['design']['design_preloader']['preloader_bg_type'] = array(
        '#type' => 'select',
        '#title'    => 'Choose type of preloader background',
        '#options'  => array(
            'skin'  => 'Same skin of whole site',
            'custom'    => 'Custom color'
        ),
        '#default_value'    => theme_get_setting('preloader_bg_type','md_magnum')
    );
    $form['md_magnum_settings']['design']['design_preloader']['preloader_bg_color'] = array(
        '#type'          => 'textfield',
        '#title'         => t('Preloader Background-color'),
        '#default_value' => theme_get_setting('preloader_bg_color','md_magnum'),
        '#prefix' => '<div id="preloader-bg-color" class="form-font-color">',
        '#suffix' => '</div>'
    );
    $form['md_magnum_settings']['design']['design_preloader']['preloader_type'] = array(
        '#type' => 'select',
        '#title'    => 'Choose type of loading status',
        '#options'  => array(
            '1' => 'Type 1',
            '2' => 'Type 2',
            '3' => 'Type 3',
            '4' => 'Type 4',
            '5' => 'Type 5',
            '6' => 'Type 6',
            '7' => 'Type 7',
            '8' => 'Type 8',
        ),
        '#default_value' => theme_get_setting('preloader_type','md_magnum'),
    );
    $form['md_magnum_settings']['design']['design_preloader']['preloader_enable_logo'] = array(
        '#type' => 'checkbox',
        '#title'    => 'Enable Preloader Logo',
        '#default_value'    => theme_get_setting('preloader_enable_logo','md_magnum')
    );
    $form['md_magnum_settings']['design']['design_preloader']['preloader_logo_path'] = array(
        '#type' => 'textfield',
        '#title' => t('Path to custom pre-loader logo image'),
        '#default_value' =>  theme_get_setting('preloader_logo_path','md_magnum'),
    );
    $form['md_magnum_settings']['design']['design_preloader']['preloader_logo_upload'] = array(
        '#type' => 'file',
    );

    /* 3.   Menu
    --------------------------------------------------------------------------*/
    $form['md_magnum_settings']['design']['design_menu'] = array(
        '#type' 					=> 'fieldset',
        '#weight' 				=> -5,
        '#prefix'  				=> '<div id="ds-menu" class="md-tabcontent clearfix"><h3>Menu Configuration</h3>',
        '#suffix'        => '</div><!-- / #ds-general -->',
    );
    $form['md_magnum_settings']['design']['design_menu']['menu_sticky'] = array(
        '#type' => 'checkbox',
        '#title'    => 'Enable Menu Sticky',
        '#default_value'    => theme_get_setting('menu_sticky','md_magnum')
    );
    $form['md_magnum_settings']['design']['design_menu']['menu_custom'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="menu-custom">',
        '#suffix'   => '</div>'
    );
    $form['md_magnum_settings']['design']['design_menu']['menu_custom']['menu_bg_color'] = array(
        '#type'          => 'textfield',
        '#title'         => t('Menu Background Color'),
        '#default_value' => theme_get_setting('menu_bg_color','md_magnum') ? theme_get_setting('menu_bg_color','md_magnum') : '1A1A1A',
        '#prefix' => '<div class="form-font-color">',
        '#suffix' => '</div>'
    );
    $form['md_magnum_settings']['design']['design_menu']['menu_custom']['menu_link_color'] = array(
        '#type'          => 'textfield',
        '#title'         => t('Menu Link Color'),
        '#default_value' => theme_get_setting('menu_link_color','md_magnum') ? theme_get_setting('menu_link_color','md_magnum') : '7A7A7A',
        '#prefix' => '<div class="form-font-color">',
        '#suffix' => '</div>'
    );
    $form['md_magnum_settings']['design']['design_menu']['menu_custom']['menu_link_hover_color'] = array(
        '#type'          => 'textfield',
        '#title'         => t('Menu Link Hover Color'),
        '#default_value' => theme_get_setting('menu_link_hover_color','md_magnum') ? theme_get_setting('menu_link_hover_color','md_magnum') : 'FFFFFF',
        '#prefix' => '<div class="form-font-color">',
        '#suffix' => '</div>'
    );

    /* 4.   Header
    --------------------------------------------------------------------------*/
    $form['md_magnum_settings']['design']['design_header'] = array(
        '#type'             => 'fieldset',
        '#weight' 				=> -6,
        '#prefix'  				=> '<div id="ds-header" class="md-tabcontent clearfix">',
        '#suffix'        => '</div><!-- / #ds-block -->',
    );
    $form['md_magnum_settings']['design']['design_header']['header_size'] = array(
        '#type' => 'select',
        '#title'    => 'Choose header size',
        '#options'  => array(
            'full'     => 'Full',
            'short'    => 'Short',
            'custom'    => 'Custom Height'
        ),
        '#default_value'    => theme_get_setting('header_size'),
        '#attributes'   => array(
            'class' => array('header-size')
        )
    );
    $form['md_magnum_settings']['design']['design_header']['header_custom_height'] = array(
        '#type' => 'textfield',
        '#title'    => 'Custom header height',
        '#default_value'    => theme_get_setting('header_custom_height','md_magnum'),
        '#field_suffix' => 'px'
    );
    $form['md_magnum_settings']['design']['design_header']['header_background_type'] = array(
        '#type' => 'select',
        '#title'    => 'Choose header background type',
        '#options'  => array(
            'md_fullscreen_slider' => 'MD Fullscreen Slider',
            'custom'    => 'Custom Image Background',
            'video'     => ' Custom Video Background (only support youtube)',
        ),
        '#default_value'    => theme_get_setting('header_background_type','md_magnum'),
        '#attributes'   => array(
            'class' => array('header-background-type')
        ),
        '#description' => 'To use MD Fullscreen Slider you need remove "Header Block" from header region and replace with your custom slider block '.l('here',''.$base_url.'/admin/structure/block'),
    );

    $form['md_magnum_settings']['design']['design_header']['header_image'] = array(
        '#type' => 'fieldset',
        '#title' => 'Custom Image Background',
        '#prefix'   => '<div id="header-image-wrapper">',
        "#suffix"   => '</div>',
    );
    $form['md_magnum_settings']['design']['design_header']['header_video'] = array(
        '#type' => 'fieldset',
        '#title' => 'Custom Video Background',
        '#prefix' => '<div id="header-video-wrapper">',
        '#suffix' => '</div>',
        '#attributes' => array(
            'class' => array('header-video-wrapper'),
        )
    );
    $form['md_magnum_settings']['design']['design_header']['header_video']['header_video_play'] =  array(
        '#type' => 'checkbox',
        '#title'    => 'Auto Play Video',
        '#default_value'    => theme_get_setting('header_video_play','md_magnum'),
    );
    $form['md_magnum_settings']['design']['design_header']['header_video']['header_video_resolution'] =  array(
        '#type' => 'select',
        '#title'    => 'Choose Video Resolution',
        '#options'  => array(
            'default'   => 'Default',
            'medium'    => 'Medium',
            'small'     => 'Small',
            'large'     => 'Large',
            'hd720'     => 'Hd720',
            'hd1080'     => 'Hd1080',
            'highres'     => 'HighRes',
        ),
        '#default_value'    => theme_get_setting('header_video_resolution','md_magnum'),
    );
    $form['md_magnum_settings']['design']['design_header']['header_video']['header_video_link'] = array(
        '#type' => 'textfield',
        '#title'    => 'Custom Video Link',
        '#attributes' => array(
            'class' => array('header_video_link'),
        ),
        '#default_value'    => theme_get_setting('header_video_link','md_magnum'),
        '#maxlength' => 255,
    );
    $form['md_magnum_settings']['design']['design_header']['header_video']['header_video_image_fallback'] = array(
        '#type' => 'textfield',
        '#title' => '<h3>Video Fallback Image</h3>',
        '#default_value' =>  theme_get_setting('header_video_image_fallback','md_magnum'),
        '#description' => 'This image use for display when video stop, pause or display in mobile device',
        '#maxlength' => 255,
    );
    $form['md_magnum_settings']['design']['design_header']['header_video']['header_video_image_fallback_upload'] = array(
        '#type' => 'file',

    );
    $form['md_magnum_settings']['design']['design_header']['header_video']['header_video_content_display'] = array(
        '#type' => 'select',
        '#title'    => 'Choose type of text and button display',
        '#options'  => array(
            '1'    => 'Style 1',
            '2'    => 'Style 2',
        ),
        '#default_value'    => theme_get_setting('header_video_content_display','md_magnum'),
    );
    $form['md_magnum_settings']['design']['design_header']['header_video']['hd_vd_content_1'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="hd-vd-ct-dp-1">',
        '#suffix'   => '</div>'
    );
    $form['md_magnum_settings']['design']['design_header']['header_video']['hd_vd_content_1']['hd_vd_ct_dp_1_big_text'] = array(
        '#type' => 'textfield',
        '#title'    => 'Custom Big Text',
        '#default_value'    => theme_get_setting('hd_vs_ct_dp_1_big_text','md_magnum') ? theme_get_setting('hd_vs_ct_dp_1_big_text','md_magnum') : 'LET ME TELL<br>YOU A STORY',
        '#maxlength' => 255,
    );
    $form['md_magnum_settings']['design']['design_header']['header_video']['hd_vd_content_1']['hd_vd_ct_dp_1_sub_text'] = array(
        '#type' => 'textfield',
        '#title'    => 'Custom Sub Text',
        '#default_value'    => theme_get_setting('hd_vd_ct_dp_1_sub_text','md_magnum') ? theme_get_setting('hd_vd_ct_dp_1_sub_text','md_magnum') : 'Hello!',
        '#maxlength' => 255,
    );
    $form['md_magnum_settings']['design']['design_header']['header_video']['hd_vd_content_2'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="hd-vd-ct-dp-2" class="hd-vd-content-wrapper">',
        '#suffix'   => '</div>'
    );
    $form['md_magnum_settings']['design']['design_header']['header_video']['hd_vd_content_2']['hd_vd_ct_2_big_text'] = array(
        '#type' => 'textfield',
        '#title'    => 'Header Video Content 2 Big Text',
        '#default_value'    => theme_get_setting('hd_vd_ct_2_big_text','md_magnum')
    );
    $form['md_magnum_settings']['design']['design_header']['header_video']['hd_vd_content_2']['hd_vd_ct_2_sub_text'] = array(
        '#type' => 'textfield',
        '#title'    => 'Header Video Content 2 Sub Text',
        '#default_value'    => theme_get_setting('hd_vd_ct_2_sub_text','md_magnum')
    );
    $form['md_magnum_settings']['design']['design_header']['header_video']['hd_vd_content_2']['hd_vd_ct_2_icon_content_wrapper'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="hd-vd-ct-2-icon-wrapper" class="hd-vd-ct-2-icon-wrapper"><h3>Header Video Content 2 Icon</h3>',
        '#suffix'   => '</div>'
    );
    $max_num = theme_get_setting('hd_vd_ct_2_icon_max_num','md_magnum') ? theme_get_setting('hd_vd_ct_2_icon_max_num','md_magnum') : 1;
    $form['md_magnum_settings']['design']['design_header']['header_video']['hd_vd_content_2']['hd_vd_ct_2_icon_content_wrapper']['hd_popup_add_wrapper'] = array(
        '#markup'   => '<a class="add-more" data-preview="hd_vd_ct_2_icon_preview" data-max-num="'.$max_num.'" href="#hd-vd-ct-2-icon-sortable-no'.$max_num.'">Add More</a>',
    );
    $form['md_magnum_settings']['design']['design_header']['header_video']['hd_vd_content_2']['hd_vd_ct_2_icon_content_wrapper']['hd_popup_close_wrapper'] = array(
        '#markup' => '</div>'
    );
    $form['md_magnum_settings']['design']['design_header']['header_video']['hd_vd_content_2']['hd_vd_ct_2_icon_content_wrapper']['hd_vd_ct_2_icon_preview'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="hd_vd_ct_2_icon_preview" class="data-container"><div class="popup-wrapper"></div>',
        '#sufix'    => '</div>'
    );
    $form['md_magnum_settings']['design']['design_header']['header_video']['hd_vd_content_2']['hd_vd_ct_2_icon_content_wrapper']['hd_vd_ct_2_icon_order'] = array(
        '#type' => 'hidden',
        '#attributes' => array(
            'class'    => 'hidden-order'
        ),
    );
    $form['md_magnum_settings']['design']['design_header']['header_video']['hd_vd_content_2']['hd_vd_ct_2_icon_content_wrapper']['hd_vd_ct_2_icon_max_num'] = array(
        '#type' => 'hidden',
        '#attributes' => array(
            'class'    => 'hidden-num'
        ),
        '#default_value' => theme_get_setting('hd_vd_ct_2_icon_max_num','md_magnum') ? theme_get_setting('hd_vd_ct_2_icon_max_num','md_magnum') : 1,
    );
    $form['md_magnum_settings']['design']['design_header']['header_video']['hd_vd_content_2']['hd_vd_ct_2_icon_content_wrapper']['hd_vd_ct_2_icon_preview']["hd_vd_preview_openhtml"] = array(
        '#markup'   => '<ul id="hd_vd_ct_2_icon_sortable" class="sortable">'
    );
    if(theme_get_setting('hd_vd_ct_2_icon','md_magnum') && count(theme_get_setting('hd_vd_ct_2_icon','md_magnum')) > 1) {
        $hd_vd_ct_2_icon = theme_get_setting('hd_vd_ct_2_icon','md_magnum');
        foreach($hd_vd_ct_2_icon as $key => $value) {
            $explode = explode("_",$key);
            end($explode);
            $num = current($explode);
            $form['md_magnum_settings']['design']['design_header']['header_video']['hd_vd_content_2']['hd_vd_ct_2_icon_content_wrapper']['hd_vd_ct_2_icon_preview'][$key.'_openhtml'] = array(
                '#markup' => '<li id="hd-vd-slide-sortable-'.$num.'" class="draggable-item sortable-item toggle-item" data-num="'.substr($num,2).'" data-id="hd-vd-slide-sortable-no'.substr($num,2).'">'
            );
            $hd_vd_ct_2_icon_icon = $hd_vd_ct_2_icon[$key]['icon'];
            $form['md_magnum_settings']['design']['design_header']['header_video']['hd_vd_content_2']['hd_vd_ct_2_icon_content_wrapper']['hd_vd_ct_2_icon_preview'][$key]['hd_vd_ct_2_icon_icon_'.$num] = array(
                '#type' => 'icon_selector',
                '#title'    => 'Icon',
                '#default_bundle' => isset($hd_vd_ct_2_icon_icon['bundle']) ? $hd_vd_ct_2_icon_icon['bundle'] : '',
                '#default_icon' => $hd_vd_ct_2_icon_icon['icon'],
                '#attributes'   => array(
                    'class' => array('icon-select'),
                    'id'    => array('hd-vd-ct-2-icon-'.$num.'')
                )
            );
            $form['md_magnum_settings']['design']['design_header']['header_video']['hd_vd_content_2']['hd_vd_ct_2_icon_content_wrapper']['hd_vd_ct_2_icon_preview'][$key]['hd_vd_ct_2_icon_link_'.$num] = array(
                '#type' => 'textfield',
                '#title'    => 'Icon Link',
                '#default_value'    => $hd_vd_ct_2_icon[$key]['link'],
            );
            $form['md_magnum_settings']['design']['design_header']['header_video']['hd_vd_content_2']['hd_vd_ct_2_icon_content_wrapper']['hd_vd_ct_2_icon_preview'][$key]['hd_vd_ct_2_icon_title_'.$num] = array(
                '#type' => 'textfield',
                '#title'    => 'Title',
                '#default_value'    => $hd_vd_ct_2_icon[$key]['title'],
            );
            $form['md_magnum_settings']['design']['design_header']['header_video']['hd_vd_content_2']['hd_vd_ct_2_icon_content_wrapper']['hd_vd_ct_2_icon_preview'][$key]['hd_vd_ct_2_icon_sub_title_'.$num] = array(
                '#type' => 'textarea',
                '#title'    => 'Sub Title',
                '#resizable'    => FALSE,
                '#default_value'    => $hd_vd_ct_2_icon[$key]['sub_title'],
            );
            $form['md_magnum_settings']['design']['design_header']['header_video']['hd_vd_content_2']['hd_vd_ct_2_icon_content_wrapper']['hd_vd_ct_2_icon_preview'][$key.'_closehtml'] = array(
                '#markup' => '<div class="preview-controls"><input class="remove form-submit" value="Remove"></div><div class="preview-demo"></div></li>'
            );
        }
    } else {
        $form['md_magnum_settings']['design']['design_header']['header_video']['hd_vd_content_2']['hd_vd_ct_2_icon_content_wrapper']['hd_vd_ct_2_icon_preview']['hd_vd_ct_2_icon_sortable_no1_openhtml'] = array(
            '#markup' => '<li id="hd-vd-ct-2-icon-sortable-no1" class="draggable-item sortable-item toggle-item" data-num="1" data-id="hd-vd-ct-2-icon-sortable-no1">'
        );
        $hd_vd_ct_2_icon_icon1 = theme_get_setting('hd_vd_ct_2_icon_icon_no1','md_magnum');
        $form['md_magnum_settings']['design']['design_header']['header_video']['hd_vd_content_2']['hd_vd_ct_2_icon_content_wrapper']['hd_vd_ct_2_icon_preview']['hd_vd_ct_2_icon_icon_no1'] = array(
            '#type' => 'icon_selector',
            '#title'    => 'Icon',
            '#default_bundle' => isset($hd_vd_ct_2_icon_icon1['bundle']) ? $hd_vd_ct_2_icon_icon1['bundle'] : '',
            '#default_icon' => $hd_vd_ct_2_icon_icon1['icon'],
            '#attributes'   => array(
                'class' => array('icon-select'),
                'id'    => array('hd-vd-ct-2-icon-no1')
            )
        );
        $form['md_magnum_settings']['design']['design_header']['header_video']['hd_vd_content_2']['hd_vd_ct_2_icon_content_wrapper']['hd_vd_ct_2_icon_preview']['hd_vd_ct_2_icon_link_no1'] = array(
            '#type' => 'textfield',
            '#title'    => 'Icon Link',
            '#default_value'    => theme_get_setting('hd_vd_ct_2_icon_link_no1','md_magnum')
        );
        $form['md_magnum_settings']['design']['design_header']['header_video']['hd_vd_content_2']['hd_vd_ct_2_icon_content_wrapper']['hd_vd_ct_2_icon_preview']['hd_vd_ct_2_icon_title_no1'] = array(
            '#type' => 'textfield',
            '#title'    => 'Title',
            '#default_value'    => theme_get_setting('hd_vd_ct_2_icon_title_no1','md_magnum')
        );
        $form['md_magnum_settings']['design']['design_header']['header_video']['hd_vd_content_2']['hd_vd_ct_2_icon_content_wrapper']['hd_vd_ct_2_icon_preview']['hd_vd_ct_2_icon_sub_title_no1'] = array(
            '#type' => 'textarea',
            '#title'    => 'Sub Title',
            '#resizable'    => FALSE,
            '#default_value'    => theme_get_setting('hd_vd_ct_2_icon_sub_title_no1','md_magnum')
        );
        $form['md_magnum_settings']['design']['design_header']['header_video']['hd_vd_content_2']['hd_vd_ct_2_icon_content_wrapper']['hd_vd_ct_2_icon_preview']['hd_vd_ct_2_icon_sortable_no1_closehtml'] = array(
            '#markup' => '<div class="preview-controls"><input class="remove form-submit" value="Remove"></div><div class="preview-demo"></div></li>'
        );
    }
    $form['md_magnum_settings']['design']['design_header']['header_video']['hd_vd_content_2']['hd_vd_ct_2_icon_content_wrapper']['hd_vd_ct_2_icon_preview']["hd_vd_preview_closehtml"] = array(
        '#markup'   => '</ul>'
    );


    $form['md_magnum_settings']['design']['design_header']['header_image']['header_slide_wrapper'] = array(
        '#type' => 'fieldset',
        '#prefix' => '<div id="header-slide-wrapper">',
        '#suffix' => '</div>',
        '#attributes' => array(
            'class' => array('header-slider-wrapper'),
        )
    );
    $form['md_magnum_settings']['design']['design_header']['header_image']['header_slide_wrapper']['header_slide_effect'] = array(
        '#type' => 'select',
        '#prefix'   => '<div id="header-slide-effect">',
        '#suffix'   =>  '</div>',
        '#title'    => 'Choose Slide Image Effect',
        '#options'  => array(
            'linear' => 'Linear',
            'swing'   => 'Swing',
            'easeInQuad'   => 'easeInQuad',
            'easeOutQuad'  => 'easeOutQuad',
            'easeInOutQuad'  => 'easeInOutQuad',
            'easeInCubic'  => 'easeInCubic',
            'easeOutCubic'  => 'easeOutCubic',
            'easeInOutCubic'  => 'easeInOutCubic',
            'easeInQuart'  => 'easeInQuart',
            'easeOutQuart'  => 'easeOutQuart',
            'easeInOutQuart'  => 'easeInOutQuart',
            'easeInQuint'  => 'easeInQuint',
            'easeOutQuint'  => 'easeOutQuint',
            'easeInOutQuint'  => 'easeInOutQuint',
            'easeInExpo'  => 'easeInExpo',
            'easeOutExpo'  => 'easeOutExpo',
            'easeInOutExpo'  => 'easeInOutExpo',
            'easeInSine'  => 'easeInSine',
            'easeOutSine'  => 'easeOutSine',
            'easeInOutSine'  => 'easeInOutSine',
            'easeInCirc'  => 'easeInCirc',
            'easeOutCirc'  => 'easeOutCirc',
            'easeInBack'  => 'easeInBack',
            'easeOutBack'  => 'easeOutBack',
            'easeInOutBack'  => 'easeInOutBack',
        ),
        '#default_value'    => theme_get_setting('header_slide_effect','md_magnum') ? theme_get_setting('header_slide_effect','md_magnum') : 'fade',
        '#description' => 'Visit '.l('here','http://jqueryui.com/resources/demos/effect/easing.html').' for more detail. Some effect are removed for better display reason.',
    );
    $form['md_magnum_settings']['design']['design_header']['header_image']['header_slide_wrapper']['header_slide_delay'] = array(
        '#type' => 'textfield',
        '#title'    => 'Slide Timer Delay',
        '#default_value'    => theme_get_setting('header_slide_delay','md_magnum') ? theme_get_setting('header_slide_delay','md_magnum') : '4000',
        '#description' => 'Time to change each slide (milisecond)',
    );
    $form['md_magnum_settings']['design']['design_header']['header_image']['header_slide_wrapper']['header_slide_effect_time'] = array(
        '#type' => 'textfield',
        '#title'    => 'Effect time',
        '#default_value'    => theme_get_setting('header_slide_effect_time','md_magnum') ? theme_get_setting('header_slide_effect_time','md_magnum') : '1000',
        '#description' => 'Effect time when switching slide (milisecond)',
    );
    $form['md_magnum_settings']['design']['design_header']['header_image']['hd_image_slide_content_wrapper'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="hd-image-slide-wrapper" class="hd-image-slide-wrapper"><h3>Header Image Slide</h3>',
        '#suffix'   => '</div>'
    );
    $max_num = theme_get_setting('hd_image_slide_max_num','md_magnum') ? theme_get_setting('hd_image_slide_max_num','md_magnum') : 1;
    $form['md_magnum_settings']['design']['design_header']['header_image']['hd_image_slide_content_wrapper']['hd_popup_add_wrapper'] = array(
        '#markup'   => '<a class="add-more" data-preview="hd_image_slide_preview" data-max-num="'.$max_num.'" href="#hd-image-slide-sortable-no'.$max_num.'">Add More</a>',
    );
    $form['md_magnum_settings']['design']['design_header']['header_image']['hd_image_slide_content_wrapper']['hd_popup_close_wrapper'] = array(
        '#markup' => '</div>'
    );
    $form['md_magnum_settings']['design']['design_header']['header_image']['hd_image_slide_content_wrapper']['hd_image_slide_preview'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="hd_image_slide_preview" class="data-container"><div class="popup-wrapper"></div>',
        '#sufix'    => '</div>'
    );
    $form['md_magnum_settings']['design']['design_header']['header_image']['hd_image_slide_content_wrapper']['hd_image_slide_order'] = array(
        '#type' => 'hidden',
        '#attributes' => array(
            'class'    => 'hidden-order'
        ),
    );
    $form['md_magnum_settings']['design']['design_header']['header_image']['hd_image_slide_content_wrapper']['hd_image_slide_max_num'] = array(
        '#type' => 'hidden',
        '#attributes' => array(
            'class'    => 'hidden-num'
        ),
        '#default_value' => theme_get_setting('hd_image_slide_max_num','md_magnum') ? theme_get_setting('hd_image_slide_max_num','md_magnum') : 1,
    );
    $form['md_magnum_settings']['design']['design_header']['header_image']['hd_image_slide_content_wrapper']['hd_image_slide_preview']["hd_image_slide_preview_openhtml"] = array(
        '#markup'   => '<ul id="hd_image_slide_sortable" class="sortable">'
    );
    if(theme_get_setting('hd_image_slide','md_magnum')) {
        $hd_image_slide = theme_get_setting('hd_image_slide','md_magnum');

        foreach($hd_image_slide as $key => $value) {
            $explode = explode("_",$key);
            end($explode);
            $num = current($explode);
            $form['md_magnum_settings']['design']['design_header']['header_image']['hd_image_slide_content_wrapper']['hd_image_slide_preview'][$key.'_openhtml'] = array(
                '#markup' => '<li id="hd-image-slide-sortable-'.$num.'" class="draggable-item sortable-item toggle-item" data-num="'.substr($num,2).'" data-id="hd-image-slide-sortable-no'.substr($num,2).'">'
            );
            $form['md_magnum_settings']['design']['design_header']['header_image']['hd_image_slide_content_wrapper']['hd_image_slide_preview'][$key]['hd_image_slide_path_'.$num.''] = array(
                '#type' => 'textfield',
                '#title' => t('Path to custom background image'),
                '#default_value' =>  $hd_image_slide[$key]['image'],
                '#prefix' => '<div>',
                '#maxlength' => 1000,
            );
            $form['md_magnum_settings']['design']['design_header']['header_image']['hd_image_slide_content_wrapper']['hd_image_slide_preview'][$key]['hd_image_slide_upload_'.$num.''] = array(
                '#type' => 'file',
                '#suffix' => '</div>'
            );

            $form['md_magnum_settings']['design']['design_header']['header_image']['hd_image_slide_content_wrapper']['hd_image_slide_preview'][$key.'_closehtml'] = array(
                '#markup' => '<div class="preview-controls"><input class="remove form-submit" value="Remove"></div><div class="preview-demo"></div></li>'
            );
        }
    } else {
        $form['md_magnum_settings']['design']['design_header']['header_image']['hd_image_slide_content_wrapper']['hd_image_slide_preview']['hd_image_slide_sortable_no1_openhtml'] = array(
            '#markup' => '<li id="hd-image-slide-sortable-no1" class="draggable-item sortable-item toggle-item" data-num="1" data-id="hd-image-slide-sortable-no1">'
        );
        $form['md_magnum_settings']['design']['design_header']['header_image']['hd_image_slide_content_wrapper']['hd_image_slide_preview']['hd_image_slide_path_no1'] = array(
            '#type' => 'textfield',
            '#title' => t('Path to custom background image'),
            '#default_value' =>  theme_get_setting('hd_image_slide_path_no1','md_magnum'),
            '#prefix' => '<div>',
            '#maxlength' => 1000,
        );
        $form['md_magnum_settings']['design']['design_header']['header_image']['hd_image_slide_content_wrapper']['hd_image_slide_preview']['hd_image_slide_upload_no1'] = array(
            '#type' => 'file',
            '#suffix' => '</div>'
        );
        $form['md_magnum_settings']['design']['design_header']['header_image']['hd_image_slide_content_wrapper']['hd_image_slide_preview']['hd_image_slide_sortable_no1_closehtml'] = array(
            '#markup' => '<div class="preview-controls"><input class="remove form-submit" value="Remove"></div><div class="preview-demo"></div></li>'
        );
    }
    $form['md_magnum_settings']['design']['design_header']['header_image']['hd_image_slide_content_wrapper']['hd_image_slide_preview']["hd_image_slide_preview_closehtml"] = array(
        '#markup'   => '</ul>'
    );


    $form['md_magnum_settings']['design']['design_header']['header_slide_content']['header_slide_content_wrapper'] = array(
        '#type' => ' fieldset',
        '#title' => 'Header Content Display',
        '#prefix'   => '<div id="header-content-wrapper">',
        '#suffix'   => '</div>'
    );

    $form['md_magnum_settings']['design']['design_header']['header_slide_content']['header_slide_content_wrapper']['header_content_display'] = array(
        '#type' => 'select',
        '#title'    => t('Choose type of header content display'),
        '#options'  => array(
            'text'    => t('Text'),
            'text_icon'    => t('Text & Icon'),
        ),
        '#default_value' => theme_get_setting('header_content_display','md_magnum'),
        '#attributes' => array(
            'class' => array('header-content-type'),
        ),
    );
    $form['md_magnum_settings']['design']['design_header']['header_slide_content']['header_slide_content_wrapper']['header_text_display'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="header-text-display" class="header-text-display">',
        "#suffix"   => '</div>',
    );
    $form['md_magnum_settings']['design']['design_header']['header_slide_content']['header_slide_content_wrapper']['header_text_icon_display'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="header-text-icon-display" class="header-text-icon-display">',
        "#suffix"   => '</div>',
    );
    $form['md_magnum_settings']['design']['design_header']['header_slide_content']['header_slide_content_wrapper']['header_text_icon_display']['hd_slide_ct_big_text'] = array(
        '#type' => 'textfield',
        '#title'    => 'Header Big Text',
        '#default_value' => theme_get_setting('hd_slide_ct_big_text','md_magnum') ? theme_get_setting('hd_slide_ct_big_text','md_magnum') : 'Magnum',
        '#maxlength' => 255,
    );
    $form['md_magnum_settings']['design']['design_header']['header_slide_content']['header_slide_content_wrapper']['header_text_icon_display']['hd_slide_ct_sub_text'] = array(
        '#type' => 'textfield',
        '#title'    => 'Header Sub Text',
        '#default_value' => theme_get_setting('hd_slide_ct_sub_text','md_magnum') ? theme_get_setting('hd_slide_ct_sub_text','md_magnum') : 'Premium Stuff',
        '#maxlength' => 255,
    );
    $max_num = theme_get_setting('hd_slide_ct_text_icon_max_num','md_magnum') ? theme_get_setting('hd_slide_ct_text_icon_max_num','md_magnum') : 1;
    $form['md_magnum_settings']['design']['design_header']['header_slide_content']['header_slide_content_wrapper']['header_text_icon_display']['hd_popup_add_wrapper'] = array(
        '#markup'   => '<a class="add-more" data-preview="hd_slide_ct_text_icon_preview" data-max-num="'.$max_num.'" href="#hd-slide-ct-text-icon-sortable-no'.$max_num.'">Add More</a>',
    );
    $form['md_magnum_settings']['design']['design_header']['header_slide_content']['header_slide_content_wrapper']['header_text_icon_display']['hd_popup_close_wrapper'] = array(
        '#markup' => '</div>'
    );
    $form['md_magnum_settings']['design']['design_header']['header_slide_content']['header_slide_content_wrapper']['header_text_icon_display']['hd_slide_ct_text_icon_preview'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="hd_slide_ct_text_icon_preview" class="data-container"><div class="popup-wrapper"></div>',
        '#sufix'    => '</div>'
    );
    $form['md_magnum_settings']['design']['design_header']['header_slide_content']['header_slide_content_wrapper']['header_text_icon_display']['hd_slide_ct_text_icon_order'] = array(
        '#type' => 'hidden',
        '#attributes' => array(
            'class'    => 'hidden-order'
        ),
    );
    $form['md_magnum_settings']['design']['design_header']['header_slide_content']['header_slide_content_wrapper']['header_text_icon_display']['hd_slide_ct_text_icon_max_num'] = array(
        '#type' => 'hidden',
        '#attributes' => array(
            'class'    => 'hidden-num'
        ),
        '#default_value' => theme_get_setting('hd_slide_ct_text_icon_max_num','md_magnum') ? theme_get_setting('hd_slide_ct_text_icon_max_num','md_magnum') : 1,
    );
    $form['md_magnum_settings']['design']['design_header']['header_slide_content']['header_slide_content_wrapper']['header_text_icon_display']['hd_slide_ct_text_icon_preview']["hd_vd_preview_openhtml"] = array(
        '#markup'   => '<ul id="hd_slide_ct_text_icon_sortable" class="sortable">'
    );
    if(theme_get_setting('hd_slide_ct_text_icon','md_magnum')) {
        $hd_slide_ct_text_icon = theme_get_setting('hd_slide_ct_text_icon','md_magnum');
        foreach($hd_slide_ct_text_icon as $key => $value) {
            $explode = explode("_",$key);
            end($explode);
            $num = current($explode);
            $form['md_magnum_settings']['design']['design_header']['header_slide_content']['header_slide_content_wrapper']['header_text_icon_display']['hd_slide_ct_text_icon_preview'][$key.'_openhtml'] = array(
                '#markup' => '<li id="hd-slide-ct-text-icon-sortable-'.$num.'" class="draggable-item sortable-item toggle-item" data-num="'.substr($num,2).'" data-id="hd-slide-ct-text-icon-sortable-no'.substr($num,2).'">'
            );
            if(isset($hd_slide_ct_text_icon[$key]['icon'])) {
                $hd_slide_ct_text_icon_icon = $hd_slide_ct_text_icon[$key]['icon'];
            }
            $form['md_magnum_settings']['design']['design_header']['header_slide_content']['header_slide_content_wrapper']['header_text_icon_display']['hd_slide_ct_text_icon_preview'][$key]['hd_slide_ct_text_icon_icon_'.$num] = array(
                '#type' => 'icon_selector',
                '#title'    => 'Icon',
                '#default_bundle' => isset($hd_slide_ct_text_icon_icon['bundle']) ? $hd_slide_ct_text_icon_icon['bundle'] : '',
                '#default_icon' => isset($hd_slide_ct_text_icon_icon['icon']) ? $hd_slide_ct_text_icon_icon['icon'] : '',
                '#attributes'   => array(
                    'class' => array('icon-select'),
                    'id'    => array('hd-slide-ct-text-icon-'.$num.'')
                )
            );
            $form['md_magnum_settings']['design']['design_header']['header_slide_content']['header_slide_content_wrapper']['header_text_icon_display']['hd_slide_ct_text_icon_preview'][$key]['hd_slide_ct_text_icon_link_'.$num] = array(
                '#type' => 'textfield',
                '#title'    => 'Icon Link',
                '#default_value'    => $hd_slide_ct_text_icon[$key]['link'],
            );
            $form['md_magnum_settings']['design']['design_header']['header_slide_content']['header_slide_content_wrapper']['header_text_icon_display']['hd_slide_ct_text_icon_preview'][$key]['hd_slide_ct_text_icon_title_'.$num] = array(
                '#type' => 'textfield',
                '#title'    => 'Title',
                '#default_value'    => $hd_slide_ct_text_icon[$key]['title'],
            );
            $form['md_magnum_settings']['design']['design_header']['header_slide_content']['header_slide_content_wrapper']['header_text_icon_display']['hd_slide_ct_text_icon_preview'][$key]['hd_slide_ct_text_icon_sub_title_'.$num] = array(
                '#type' => 'textarea',
                '#title'    => 'Sub Title',
                '#resizable'    => FALSE,
                '#default_value'    => $hd_slide_ct_text_icon[$key]['sub_title'],
            );
            $form['md_magnum_settings']['design']['design_header']['header_slide_content']['header_slide_content_wrapper']['header_text_icon_display']['hd_slide_ct_text_icon_preview'][$key.'_closehtml'] = array(
                '#markup' => '<div class="preview-controls"><input class="remove form-submit" value="Remove"></div><div class="preview-demo"></div></li>'
            );
        }
    } else {
        $form['md_magnum_settings']['design']['design_header']['header_slide_content']['header_slide_content_wrapper']['header_text_icon_display']['hd_slide_ct_text_icon_preview']['hd_slide_ct_text_icon_sortable_no1_openhtml'] = array(
            '#markup' => '<li id="hd-slide-ct-text-icon-sortable-no1" class="draggable-item sortable-item toggle-item" data-num="1" data-id="hd-slide-ct-text-icon-sortable-no1">'
        );
        $hd_slide_ct_text_icon_icon1 = theme_get_setting('hd_slide_ct_text_icon_icon_no1','md_magnum');
        $form['md_magnum_settings']['design']['design_header']['header_slide_content']['header_slide_content_wrapper']['header_text_icon_display']['hd_slide_ct_text_icon_preview']['hd_slide_ct_text_icon_icon_no1'] = array(
            '#type' => 'icon_selector',
            '#title'    => 'Icon',
            '#default_bundle' => isset($hd_slide_ct_text_icon_icon1['bundle']) ? $hd_slide_ct_text_icon_icon1['bundle'] : '',
            '#default_icon' => $hd_slide_ct_text_icon_icon1['icon'],
            '#attributes'   => array(
                'class' => array('icon-select'),
                'id'    => array('hd-slide-ct-text-icon-no1')
            )
        );
        $form['md_magnum_settings']['design']['design_header']['header_slide_content']['header_slide_content_wrapper']['header_text_icon_display']['hd_slide_ct_text_icon_preview']['hd_slide_ct_text_icon_link_no1'] = array(
            '#type' => 'textfield',
            '#title'    => 'Icon Link',
            '#default_value'    => theme_get_setting('hd_slide_ct_text_icon_link_no1','md_magnum')
        );
        $form['md_magnum_settings']['design']['design_header']['header_slide_content']['header_slide_content_wrapper']['header_text_icon_display']['hd_slide_ct_text_icon_preview']['hd_slide_ct_text_icon_title_no1'] = array(
            '#type' => 'textfield',
            '#title'    => 'Title',
            '#default_value'    => theme_get_setting('hd_slide_ct_text_icon_title_no1','md_magnum')
        );
        $form['md_magnum_settings']['design']['design_header']['header_slide_content']['header_slide_content_wrapper']['header_text_icon_display']['hd_slide_ct_text_icon_preview']['hd_slide_ct_text_icon_sub_title_no1'] = array(
            '#type' => 'textarea',
            '#title'    => 'Sub Title',
            '#resizable'    => FALSE,
            '#default_value'    => theme_get_setting('hd_slide_ct_text_icon_sub_title_no1','md_magnum')
        );
        $form['md_magnum_settings']['design']['design_header']['header_slide_content']['header_slide_content_wrapper']['header_text_icon_display']['hd_slide_ct_text_icon_preview']['hd_slide_ct_text_icon_sortable_no1_closehtml'] = array(
            '#markup' => '<div class="preview-controls"><input class="remove form-submit" value="Remove"></div><div class="preview-demo"></div></li>'
        );
    }
    $form['md_magnum_settings']['design']['design_header']['header_slide_content']['header_slide_content_wrapper']['header_text_icon_display']['hd_slide_ct_text_icon_preview']["hd_vd_preview_closehtml"] = array(
        '#markup'   => '</ul>'
    );

    $max_num = theme_get_setting('hd_slide_ct_text_max_num','md_magnum') ? theme_get_setting('hd_slide_ct_text_max_num','md_magnum') : 1;
    $form['md_magnum_settings']['design']['design_header']['header_slide_content']['header_slide_content_wrapper']['header_text_display']['hd_popup_add_wrapper'] = array(
        '#markup'   => '<a class="add-more" data-preview="hd_slide_ct_text_preview" data-max-num="'.$max_num.'" href="#hd-slide-ct-text-sortable-no'.$max_num.'">Add More</a>',
    );
    $form['md_magnum_settings']['design']['design_header']['header_slide_content']['header_slide_content_wrapper']['header_text_display']['hd_popup_close_wrapper'] = array(
        '#markup' => '</div>'
    );
    $form['md_magnum_settings']['design']['design_header']['header_slide_content']['header_slide_content_wrapper']['header_text_display']['hd_slide_ct_text_preview'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="hd_slide_ct_text_preview" class="data-container"><div class="popup-wrapper"></div>',
        '#sufix'    => '</div>'
    );
    $form['md_magnum_settings']['design']['design_header']['header_slide_content']['header_slide_content_wrapper']['header_text_display']['hd_slide_ct_text_order'] = array(
        '#type' => 'hidden',
        '#attributes' => array(
            'class'    => 'hidden-order'
        ),
    );
    $form['md_magnum_settings']['design']['design_header']['header_slide_content']['header_slide_content_wrapper']['header_text_display']['hd_slide_ct_text_max_num'] = array(
        '#type' => 'hidden',
        '#attributes' => array(
            'class'    => 'hidden-num'
        ),
        '#default_value' => theme_get_setting('hd_slide_ct_text_max_num','md_magnum') ? theme_get_setting('hd_slide_ct_text_max_num','md_magnum') : 1,
    );
    $form['md_magnum_settings']['design']['design_header']['header_slide_content']['header_slide_content_wrapper']['header_text_display']['hd_slide_ct_text_preview']["hd_vd_preview_openhtml"] = array(
        '#markup'   => '<ul id="hd_slide_ct_text_sortable" class="sortable">'
    );
    if(theme_get_setting('hd_slide_ct_text','md_magnum')) {
        $hd_slide_ct_text = theme_get_setting('hd_slide_ct_text','md_magnum');
        foreach($hd_slide_ct_text as $key => $value) {
            $explode = explode("_",$key);
            end($explode);
            $num = current($explode);
            $form['md_magnum_settings']['design']['design_header']['header_slide_content']['header_slide_content_wrapper']['header_text_display']['hd_slide_ct_text_preview'][$key.'_openhtml'] = array(
                '#markup' => '<li id="hd-slide-ct-text-sortable-'.$num.'" class="draggable-item sortable-item toggle-item" data-num="'.substr($num,2).'" data-id="hd-slide-ct-text-sortable-no'.substr($num,2).'">'
            );
            $form['md_magnum_settings']['design']['design_header']['header_slide_content']['header_slide_content_wrapper']['header_text_display']['hd_slide_ct_text_preview'][$key]['hd_slide_ct_text_title_'.$num] = array(
                '#type' => 'textfield',
                '#title'    => 'Title',
                '#default_value'    => $hd_slide_ct_text[$key]['title'],
            );
            $form['md_magnum_settings']['design']['design_header']['header_slide_content']['header_slide_content_wrapper']['header_text_display']['hd_slide_ct_text_preview'][$key]['hd_slide_ct_text_sub_title_'.$num] = array(
                '#type' => 'textfield',
                '#title'    => 'Sub Title',
                '#default_value'    => $hd_slide_ct_text[$key]['sub_title'],
            );
            $form['md_magnum_settings']['design']['design_header']['header_slide_content']['header_slide_content_wrapper']['header_text_display']['hd_slide_ct_text_preview'][$key]['hd_slide_ct_text_button_text_'.$num] = array(
                '#type' => 'textfield',
                '#title'    => 'Button Text',
                '#default_value'    => $hd_slide_ct_text[$key]['button_text'],
            );
            $form['md_magnum_settings']['design']['design_header']['header_slide_content']['header_slide_content_wrapper']['header_text_display']['hd_slide_ct_text_preview'][$key]['hd_slide_ct_text_button_link_'.$num] = array(
                '#type' => 'textfield',
                '#title'    => 'Button Link',
                '#default_value'    => $hd_slide_ct_text[$key]['button_link'],
            );
            $form['md_magnum_settings']['design']['design_header']['header_slide_content']['header_slide_content_wrapper']['header_text_display']['hd_slide_ct_text_preview'][$key.'_closehtml'] = array(
                '#markup' => '<div class="preview-controls"><input class="remove form-submit" value="Remove"></div><div class="preview-demo"></div></li>'
            );
        }
    } else {
        $form['md_magnum_settings']['design']['design_header']['header_slide_content']['header_slide_content_wrapper']['header_text_display']['hd_slide_ct_text_preview']['hd_slide_ct_text_sortable_no1_openhtml'] = array(
            '#markup' => '<li id="hd-slide-ct-text-sortable-no1" class="draggable-item sortable-item toggle-item" data-num="1" data-id="hd-slide-ct-text-sortable-no1">'
        );
        $form['md_magnum_settings']['design']['design_header']['header_slide_content']['header_slide_content_wrapper']['header_text_display']['hd_slide_ct_text_preview']['hd_slide_ct_text_title_no1'] = array(
            '#type' => 'textfield',
            '#title'    => 'Title',
            '#default_value'    => theme_get_setting('hd_slide_ct_text_title_no1','md_magnum')
        );
        $form['md_magnum_settings']['design']['design_header']['header_slide_content']['header_slide_content_wrapper']['header_text_display']['hd_slide_ct_text_preview']['hd_slide_ct_text_sub_title_no1'] = array(
            '#type' => 'textfield',
            '#title'    => 'Sub Title',
            '#default_value'    => theme_get_setting('hd_slide_ct_text_sub_title_no1','md_magnum')
        );
        $form['md_magnum_settings']['design']['design_header']['header_slide_content']['header_slide_content_wrapper']['header_text_display']['hd_slide_ct_text_preview']['hd_slide_ct_text_button_text_no1'] = array(
            '#type' => 'textarea',
            '#title'    => 'Button Text',
            '#default_value'    => theme_get_setting('hd_slide_ct_text_button_text_no1','md_magnum')
        );
        $form['md_magnum_settings']['design']['design_header']['header_slide_content']['header_slide_content_wrapper']['header_text_display']['hd_slide_ct_text_preview']['hd_slide_ct_text_button_link_no1'] = array(
            '#type' => 'textarea',
            '#title'    => 'Button Link',
            '#default_value'    => theme_get_setting('hd_slide_ct_text_button_link_no1','md_magnum')
        );
        $form['md_magnum_settings']['design']['design_header']['header_slide_content']['header_slide_content_wrapper']['header_text_display']['hd_slide_ct_text_preview']['hd_slide_ct_text_sortable_no1_closehtml'] = array(
            '#markup' => '<div class="preview-controls"><input class="remove form-submit" value="Remove"></div><div class="preview-demo"></div></li>'
        );
    }
    $form['md_magnum_settings']['design']['design_header']['header_slide_content']['header_slide_content_wrapper']['header_text_display']['hd_slide_ct_text_preview']["hd_vd_preview_closehtml"] = array(
        '#markup'   => '</ul>'
    );

    /* 3.	Introduction
    --------------------------------------------------------------------------*/
    $form['md_magnum_settings']['design']['design_introduction'] = array(
        '#type'             => 'fieldset',
        '#weight' 				=> -6,
        '#prefix'  				=> '<div id="ds-introduction" class="md-tabcontent clearfix">',
        '#suffix'        => '</div><!-- / #ds-block -->',
    );
    $form['md_magnum_settings']['design']['design_introduction']['intro_title'] = array(
        '#type' => 'textfield',
        '#title'    => 'Introduction Title',
        '#default_value'    => theme_get_setting('intro_title','md_magnum') ? theme_get_setting('intro_title','md_magnum') : "It's nice to meet you",
        '#maxlength' => 255,
    );
    $form['md_magnum_settings']['design']['design_introduction']['intro_des']   = array(
        '#type' => 'textarea',
        '#title'    => 'Introduction Description',
        '#default_value' => theme_get_setting('intro_des','md_magnum') ?  theme_get_setting('intro_des','md_magnum') : "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nullam ornare sem sit amet mauris bibendum, ac fringilla quam eleifend. Praesent elit tellus, venenatis in lorem ac, porta accumsan sapien. Cras malesuada feugiat magnum.",
    );
    $form['md_magnum_settings']['design']['design_introduction']['intro_button']   = array(
        '#type' => 'fieldset',
        '#title'    => '<h3>Introduction Button</h3>',
    );
    $form['md_magnum_settings']['design']['design_introduction']['intro_button']['intro_button_text'] = array(
        '#type' => 'textfield',
        '#title'    => 'Introduction Button Text',
        '#default_value'    => theme_get_setting('intro_button_text') ? theme_get_setting('intro_button_text') : 'View My Work',
        '#maxlength' => 255,
    );
    $form['md_magnum_settings']['design']['design_introduction']['intro_button']['intro_button_link'] = array(
        '#type' => 'textfield',
        '#title'    => 'Introduction Button Link',
        '#default_value'    => theme_get_setting('intro_button_link') ? theme_get_setting('intro_button_link') : '#work',
        '#maxlength' => 255,
    );


    /* 4.	Parallax
    --------------------------------------------------------------------------*/
    $form['md_magnum_settings']['design']['design_parallax'] = array(
        '#type'             => 'fieldset',
        '#weight' 				=> -7,
        '#prefix'  				=> '<div id="ds-parallax" class="md-tabcontent clearfix">',
        '#suffix'        => '</div><!-- / #ds-block -->',
    );
    $form['md_magnum_settings']['design']['design_parallax']['parallax_htmllist'] = array(
        '#markup' 				=> '<div id="md-subtabs" class="md-subtabs">
								<div class="md-subtabs-head">
		              <ul class="clearfix">
		                <li class="subtab-item clearfix first"> <a class="subtab-link" href="#parallax-1-form">Parallax 1</a> </li>
		                <li class="subtab-item clearfix"> <a class="subtab-link" href="#parallax-2-form">Parallax 2</a> </li>
		                <li class="subtab-item clearfix last"> <a class="subtab-link" href="#parallax-3-form">Parallax 3</a> </li>
		              </ul>
		            </div>',
        '#weight' 				=> -15,
    );
    $form['md_magnum_settings']['design']['design_parallax']['parallax_htmllistclose'] = array(
        '#markup' 				=> '</div><!-- /#sub-tab -->',
        '#weight' 				=> 15,
    );


        $form['md_magnum_settings']['design']['design_parallax']['parallax_1'] = array(
            '#type'             => 'fieldset',
            '#title'            => t('<h2>Parallax 1</h2>'),
            '#description'      => t(''),
            '#prefix'  				=> '<div id="parallax-1-form" class="md-subtabcontent clearfix">',
            '#suffix'        => '</div><!-- / #parallax-1 -->',
            '#weight' 				=> -5,
        );

        md_magnum_prepare_parallax_form($form,1);
    $form['md_magnum_settings']['design']['design_parallax']['parallax_2'] = array(
        '#type'             => 'fieldset',
        '#title'            => t('<h2>Parallax 2</h2>'),
        '#description'      => t(''),
        '#prefix'  				=> '<div id="parallax-2-form" class="md-subtabcontent clearfix">',
        '#suffix'        => '</div><!-- / #parallax-1 -->',
        '#weight' 				=> -4,
    );
    md_magnum_prepare_parallax_form($form,2);
    $form['md_magnum_settings']['design']['design_parallax']['parallax_3'] = array(
        '#type'             => 'fieldset',
        '#title'            => t('<h2>Parallax 3</h2>'),
        '#description'      => t(''),
        '#prefix'  				=> '<div id="parallax-3-form" class="md-subtabcontent clearfix">',
        '#suffix'        => '</div><!-- / #parallax-3 -->',
        '#weight' 				=> -3,
    );
    md_magnum_prepare_parallax_form($form,3);


    // 4. ---------------------------------- Team --------------------------------------------

    $form['md_magnum_settings']['design']['design_team'] = array(
        '#type'             => 'fieldset',
        '#weight' 				=> -8,
        '#prefix'  				=> '<div id="ds-team" class="md-tabcontent clearfix"><h3>Team (About Us) Header Configuration</h3>',
        '#suffix'        => '</div><!-- / #ds-block -->',
    );
    $form['md_magnum_settings']['design']['design_team']['enable_team_header'] = array(
        '#type' => 'checkbox',
        '#title'    => 'Show team header',
        '#default_value'    => theme_get_setting('enable_team_header','md_magnum')
    );
    $form['md_magnum_settings']['design']['design_team']['team_header'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="team-header">',
        '#suffix'   => '</div>'
    );
    $form['md_magnum_settings']['design']['design_team']['team_header']['team_background_path'] = array(
        '#type' => 'textfield',
        '#title'    => 'Change Team Header Background',
        '#default_value'    => theme_get_setting('team_background_path','md_magnum'),

    );
    $form['md_magnum_settings']['design']['design_team']['team_header']['team_background_upload'] = array(
        '#type' => 'file',
    );
    $form['md_magnum_settings']['design']['design_team']['team_header']['team_big_text'] = array(
        '#type' => 'textfield',
        '#title'    => 'Custom Team Header Big Text',
        '#default_value'    => theme_get_setting('team_big_text','md_magnum') ? theme_get_setting('team_big_text') : 'This Is Our Story'
    );
    $form['md_magnum_settings']['design']['design_team']['team_header']['team_sub_text'] = array(
        '#type' => 'textfield',
        '#title'    => 'Custom Team Header Sub Text',
        '#default_value'    => theme_get_setting('team_sub_text','md_magnum') ? theme_get_setting('team_sub_text') : 'So you get to know us better'
    );


   // 5. ---------------------------------- Footer --------------------------------------------
    $form['md_magnum_settings']['design']['design_footer'] = array(
        '#type'             => 'fieldset',
        '#weight' 				=> -8,
        '#prefix'  				=> '<div id="ds-footer" class="md-tabcontent clearfix">',
        '#suffix'        => '</div><!-- / #ds-block -->',
    );
    $form['md_magnum_settings']['design']['design_footer']['footer_background'] = array(
        '#type' => 'select',
        '#title'    => 'Choose background type of footer',
        '#options'  => array(
            'global'    => 'Global(Same header display)',
            'video' => 'Video Background',
            'custom'    => 'Custom Image Background',
            'pattern'   => 'Pattern Background',
            'color' => 'Single Color'
        ),
        '#default_value'    => theme_get_setting('footer_background','md_magnum')
    );
    $form['md_magnum_settings']['design']['design_footer']['ft_pattern_bg'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="ft-pattern-bg">',
        '#suffix' => '</div>',
    );
    $items = array();
    $path_data_dir = drupal_get_path('theme', 'md_magnum') . '/images/background/patterns';
    $files = file_scan_directory($path_data_dir, '/.png$/');
    $pattern_css = "";
    foreach ($files as $file) {
        $items[$file->name] = t('Pattern ' . $file->name);
        $pattern_css .= '#pt' . $file->name . ' {background:url(' . base_path() . drupal_get_path('theme', 'md_magnum') . '/images/background/patterns/' . $file->name . '.png) repeat 0 0;}';
    }
    drupal_add_css($pattern_css, 'inline');


    $form['md_magnum_settings']['design']['design_footer']['ft_pattern_bg']['choose_ft_pattern'] = array(
        '#type'          => 'select',
        '#title'         => t('Choose Pattern'),
        '#default_value' => theme_get_setting('choose_ft_pattern','md_magnum'),
        '#options'       => $items,
        '#prefix' => '<div id="design-ft-bg-pattern" class="clearfix">',
        '#suffix' => '</div>',
    );
    $form['md_magnum_settings']['design']['design_footer']['ft_color_bg'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="ft-color-bg">',
        '#suffix' => '</div>',
    );
    $form['md_magnum_settings']['design']['design_footer']['ft_color_bg']['ft_bg_color'] = array(
        '#type'          => 'textfield',
        '#title'         => t('Background-color'),
        '#default_value' => theme_get_setting('ft_bg_color','md_magnum'),
        '#prefix' => '<div class="form-font-color">',
        '#suffix' => '</div>'
    );
    $form['md_magnum_settings']['design']['design_footer']['footer_custom_background'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="footer-custom-background">',
        '#suffix'   => '</div>',
    );

    $form['md_magnum_settings']['design']['design_footer']['footer_custom_background']['ft_video_bg'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="ft-video-bg">',
        '#suffix'   => '</div>',
    );
    $form['md_magnum_settings']['design']['design_footer']['footer_custom_background']['ft_video_bg']['ft_video_resolution'] =  array(
        '#type' => 'select',
        '#title'    => 'Choose Video Resolution',
        '#options'  => array(
            'default'   => 'Default',
            'medium'    => 'Medium',
            'small'     => 'Small',
            'large'     => 'Large',
            'hd720'     => 'Hd720',
            'hd1080'     => 'Hd1080',
            'highres'     => 'HighRes',
        ),
        '#default_value'    => theme_get_setting('ft_video_resolution','md_magnum'),
    );
    $form['md_magnum_settings']['design']['design_footer']['footer_custom_background']['ft_video_bg']['ft_video_link'] = array(
        '#type' => 'textfield',
        '#title'    => 'Custom Video Link',
        '#attributes' => array(
            'class' => array('ft-video-link'),
        ),
        '#default_value'    => theme_get_setting('ft_video_link','md_magnum'),
    );
    $form['md_magnum_settings']['design']['design_footer']['footer_custom_background']['footer_custom_image'] = array(
        '#type' => 'fieldset',
        '#prefix'  => '<div id="footer-custom-image">',
        '#suffix'   => '</div>'
    );
    $form['md_magnum_settings']['design']['design_footer']['footer_custom_background']['footer_custom_image']['footer_slide_effect'] = array(
        '#type' => 'select',
        '#prefix'   => '<div id="header-slide-effect">',
        '#suffix'   =>  '</div>',
        '#title'    => 'Choose Slide Image Effect',
        '#options'  => array(
            'linear' => 'Linear',
            'swing'   => 'Swing',
            'easeInQuad'   => 'easeInQuad',
            'easeOutQuad'  => 'easeOutQuad',
            'easeInOutQuad'  => 'easeInOutQuad',
            'easeInCubic'  => 'easeInCubic',
            'easeOutCubic'  => 'easeOutCubic',
            'easeInOutCubic'  => 'easeInOutCubic',
            'easeInQuart'  => 'easeInQuart',
            'easeOutQuart'  => 'easeOutQuart',
            'easeInOutQuart'  => 'easeInOutQuart',
            'easeInQuint'  => 'easeInQuint',
            'easeOutQuint'  => 'easeOutQuint',
            'easeInOutQuint'  => 'easeInOutQuint',
            'easeInExpo'  => 'easeInExpo',
            'easeOutExpo'  => 'easeOutExpo',
            'easeInOutExpo'  => 'easeInOutExpo',
            'easeInSine'  => 'easeInSine',
            'easeOutSine'  => 'easeOutSine',
            'easeInOutSine'  => 'easeInOutSine',
            'easeInCirc'  => 'easeInCirc',
            'easeOutCirc'  => 'easeOutCirc',
            'easeInBack'  => 'easeInBack',
            'easeOutBack'  => 'easeOutBack',
            'easeInOutBack'  => 'easeInOutBack',
        ),
        '#default_value'    => theme_get_setting('footer_slide_effect','md_magnum') ? theme_get_setting('footer_slide_effect','md_magnum') : 'fade',
        '#description' => 'Visit '.l('here','http://jqueryui.com/resources/demos/effect/easing.html').' for more detail. Some effect are removed for better display reason.',
    );
    $form['md_magnum_settings']['design']['design_footer']['footer_custom_background']['footer_custom_image']['footer_slide_delay'] = array(
        '#type' => 'textfield',
        '#title'    => 'Slide Timer Delay',
        '#default_value'    => theme_get_setting('footer_slide_delay','md_magnum') ? theme_get_setting('footer_slide_delay','md_magnum') : '4000',
        '#description' => 'Time to change each slide (milisecond)',
    );
    $form['md_magnum_settings']['design']['design_footer']['footer_custom_background']['footer_custom_image']['header_slide_effect_time'] = array(
        '#type' => 'textfield',
        '#title'    => 'Effect time',
        '#default_value'    => theme_get_setting('footer_slide_effect_time','md_magnum') ? theme_get_setting('footer_slide_effect_time','md_magnum') : '1000',
        '#description' => 'Effect time when switching slide (milisecond)',
    );
    $form['md_magnum_settings']['design']['design_footer']['footer_custom_background']['footer_custom_image']['ft_image_slide_content_wrapper'] = array(
        '#type' => 'fieldset',
        '#prefix' => '<div id="ft-image-slide-wrapper">',
        '#suffix' => '</div>',
        '#attributes' => array(
            'class' => array('ft-slider-wrapper'),
        )
    );
    $max_num = theme_get_setting('ft_image_slide_max_num','md_magnum') ? theme_get_setting('ft_image_slide_max_num','md_magnum') : 1;
    $form['md_magnum_settings']['design']['design_footer']['footer_custom_background']['footer_custom_image']['ft_image_slide_content_wrapper']['ft_popup_add_wrapper'] = array(
        '#markup'   => '<a class="add-more" data-preview="ft_image_slide_preview" data-max-num="'.$max_num.'" href="#ft-image-slide-sortable-no'.$max_num.'">Add More</a>',
    );
    $form['md_magnum_settings']['design']['design_footer']['footer_custom_background']['footer_custom_image']['ft_image_slide_content_wrapper']['ft_popup_close_wrapper'] = array(
        '#markup' => '</div>'
    );
    $form['md_magnum_settings']['design']['design_footer']['footer_custom_background']['footer_custom_image']['ft_image_slide_content_wrapper']['ft_image_slide_preview'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="ft_image_slide_preview" class="data-container"><div class="popup-wrapper"></div>',
        '#sufix'    => '</div>'
    );
    $form['md_magnum_settings']['design']['design_footer']['footer_custom_background']['footer_custom_image']['ft_image_slide_content_wrapper']['ft_image_slide_order'] = array(
        '#type' => 'hidden',
        '#attributes' => array(
            'class'    => 'hidden-order'
        ),
    );
    $form['md_magnum_settings']['design']['design_footer']['footer_custom_background']['footer_custom_image']['ft_image_slide_content_wrapper']['ft_image_slide_max_num'] = array(
        '#type' => 'hidden',
        '#attributes' => array(
            'class'    => 'hidden-num'
        ),
        '#default_value' => theme_get_setting('ft_image_slide_max_num','md_magnum') ? theme_get_setting('ft_image_slide_max_num','md_magnum') : 1,
    );
    $form['md_magnum_settings']['design']['design_footer']['footer_custom_background']['footer_custom_image']['ft_image_slide_content_wrapper']['ft_image_slide_preview']["ft_image_slide_preview_openhtml"] = array(
        '#markup'   => '<ul id="ft_image_slide_sortable" class="sortable">'
    );
    if(theme_get_setting('ft_image_slide','md_magnum')) {
        $ft_image_slide = theme_get_setting('ft_image_slide','md_magnum');

        foreach($ft_image_slide as $key => $value) {
            $explode = explode("_",$key);
            end($explode);
            $num = current($explode);
            $form['md_magnum_settings']['design']['design_footer']['footer_custom_background']['footer_custom_image']['ft_image_slide_content_wrapper']['ft_image_slide_preview'][$key.'_openhtml'] = array(
                '#markup' => '<li id="ft-image-slide-sortable-'.$num.'" class="draggable-item sortable-item toggle-item" data-num="'.substr($num,2).'" data-id="ft-image-slide-sortable-no'.substr($num,2).'">'
            );
            $form['md_magnum_settings']['design']['design_footer']['footer_custom_background']['footer_custom_image']['ft_image_slide_content_wrapper']['ft_image_slide_preview'][$key]['ft_image_slide_path_'.$num.''] = array(
                '#type' => 'textfield',
                '#title' => t('Path to custom background image'),
                '#default_value' =>  $ft_image_slide[$key]['image'],
                '#prefix' => '<div>',
                '#maxlength' => 1000,
            );
            $form['md_magnum_settings']['design']['design_footer']['footer_custom_background']['footer_custom_image']['ft_image_slide_content_wrapper']['ft_image_slide_preview'][$key]['ft_image_slide_upload_'.$num.''] = array(
                '#type' => 'file',
                '#suffix' => '</div>'
            );

            $form['md_magnum_settings']['design']['design_footer']['footer_custom_background']['footer_custom_image']['ft_image_slide_content_wrapper']['ft_image_slide_preview'][$key.'_closehtml'] = array(
                '#markup' => '<div class="preview-controls"><input class="remove form-submit" value="Remove"></div><div class="preview-demo"></div></li>'
            );
        }
    } else {
        $form['md_magnum_settings']['design']['design_footer']['footer_custom_background']['footer_custom_image']['ft_image_slide_content_wrapper']['ft_image_slide_preview']['ft_image_slide_sortable_no1_openhtml'] = array(
            '#markup' => '<li id="ft-image-slide-sortable-no1" class="draggable-item sortable-item toggle-item" data-num="1" data-id="ft-image-slide-sortable-no1">'
        );
        $form['md_magnum_settings']['design']['design_footer']['footer_custom_background']['footer_custom_image']['ft_image_slide_content_wrapper']['ft_image_slide_preview']['ft_image_slide_path_no1'] = array(
            '#type' => 'textfield',
            '#title' => t('Path to custom background image'),
            '#default_value' =>  theme_get_setting('ft_image_slide_path_no1','md_magnum'),
            '#prefix' => '<div>',
            '#maxlength' => 1000,
        );
        $form['md_magnum_settings']['design']['design_footer']['footer_custom_background']['footer_custom_image']['ft_image_slide_content_wrapper']['ft_image_slide_preview']['ft_image_slide_upload_no1'] = array(
            '#type' => 'file',
            '#suffix' => '</div>'
        );
        $form['md_magnum_settings']['design']['design_footer']['footer_custom_background']['footer_custom_image']['ft_image_slide_content_wrapper']['ft_image_slide_preview']['ft_image_slide_sortable_no1_closehtml'] = array(
            '#markup' => '<div class="preview-controls"><input class="remove form-submit" value="Remove"></div><div class="preview-demo"></div></li>'
        );
    }
    $form['md_magnum_settings']['design']['design_footer']['footer_custom_background']['footer_custom_image']['ft_image_slide_content_wrapper']['ft_image_slide_preview']["ft_image_slide_preview_closehtml"] = array(
        '#markup'   => '</ul>'
    );
    $form['md_magnum_settings']['design']['design_footer']['footer_content_display'] = array(
        '#type' => 'select',
        '#title'    => 'Choose display content type of footer',
        '#options'  => array(
            '1' => 'Style 1',
            '2' => 'Style 2',
        ),
        '#default_value'    => theme_get_setting('footer_content_display','md_magnum')
    );
    $form['md_magnum_settings']['design']['design_footer']['footer_social_text'] = array(
        '#type' => 'textfield',
        '#title'    => 'Custom Social Text',
        '#default_value'    => theme_get_setting('footer_social_text','md_magnum') ? theme_get_setting('footer_social_text','md_magnum') : 'The Social Stuff',
        '#maxlength' => 255,
    );
    $form['md_magnum_settings']['design']['design_footer']['footer_social'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="footer-social"><h3>Custom Social Account</h3>',
        '#suffix'   => '</div>',
    );

    $form['md_magnum_settings']['design']['design_footer']['footer_social']['social_acc_wrapper'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="ft-sc-wrapper" class="ft-sc-wrapper"><h3>Footer Social Icon</h3>',
        '#suffix'   => '</div>'
    );
    $max_num = theme_get_setting('ft_sc_max_num','md_magnum') ? theme_get_setting('ft_sc_max_num','md_magnum') : 1;
    $form['md_magnum_settings']['design']['design_footer']['footer_social']['social_acc_wrapper']['ft_sc_wrapper']['ft_sc_popup_add_wrapper'] = array(
        '#markup'   => '<a class="add-more" data-preview="ft_sc_preview" data-max-num="'.$max_num.'" href="#ft-sc-sortable-no'.$max_num.'">Add More</a>',
    );
    $form['md_magnum_settings']['design']['design_footer']['footer_social']['social_acc_wrapper']['ft_sc_wrapper']['ft_sc_popup_close_wrapper'] = array(
        '#markup' => '</div>'
    );
    $form['md_magnum_settings']['design']['design_footer']['footer_social']['social_acc_wrapper']['ft_sc_wrapper']['ft_sc_preview'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="ft_sc_preview" class="data-container"><div class="popup-wrapper"></div>',
        '#sufix'    => '</div>'
    );
    $form['md_magnum_settings']['design']['design_footer']['footer_social']['social_acc_wrapper']['ft_sc_wrapper']['ft_sc_order'] = array(
        '#type' => 'hidden',
        '#attributes' => array(
            'class'    => 'hidden-order'
        ),
    );
    $form['md_magnum_settings']['design']['design_footer']['footer_social']['social_acc_wrapper']['ft_sc_wrapper']['ft_sc_max_num'] = array(
        '#type' => 'hidden',
        '#attributes' => array(
            'class'    => 'hidden-num'
        ),
        '#default_value' => theme_get_setting('ft_sc_max_num','md_magnum') ? theme_get_setting('ft_sc_max_num','md_magnum') : 1,
    );
    $form['md_magnum_settings']['design']['design_footer']['footer_social']['social_acc_wrapper']['ft_sc_wrapper']['ft_sc_preview']["ft_sc_preview_openhtml"] = array(
        '#markup'   => '<ul id="ft_sc_sortable" class="sortable">'
    );

    if(theme_get_setting('ft_sc','md_magnum') && count(theme_get_setting('ft_sc','md_magnum')) > 1) {
        $ft_sc = theme_get_setting('ft_sc','md_magnum');
        foreach($ft_sc as $key => $value) {
            $explode = explode("_",$key);
            end($explode);
            $num = current($explode);
            $ft_sc_icon = $ft_sc[$key]['icon'];
            $form['md_magnum_settings']['design']['design_footer']['footer_social']['social_acc_wrapper']['ft_sc_wrapper']['ft_sc_preview'][$key.'_openhtml'] = array(
                '#markup' => '<li id="ft-sc-sortable-'.$num.'" class="draggable-item sortable-item toggle-item" data-num="'.substr($num,2).'" data-id="ft-sc-sortable-no'.substr($num,2).'">'
            );
            $form['md_magnum_settings']['design']['design_footer']['footer_social']['social_acc_wrapper']['ft_sc_wrapper']['ft_sc_preview'][$key]['ft_sc_icon_'.$num.''] = array(
                '#type' => 'icon_selector',
                '#title'    => 'Icon',
                '#default_bundle' => isset($ft_sc_icon['bundle']) ? $ft_sc_icon['bundle'] : '',
                '#default_icon' => $ft_sc_icon['icon'],
                '#attributes'   => array(
                    'class' => array('icon-select'),
                    'id'    => array('ft-sc-no1')
                )
            );
            $form['md_magnum_settings']['design']['design_footer']['footer_social']['social_acc_wrapper']['ft_sc_wrapper']['ft_sc_preview'][$key]['ft_sc_link_'.$num.''] = array(
                '#type' => 'textfield',
                '#title' => 'Icon Link',
                '#default_value'    => $ft_sc[$key]['link']
            );
            $form['md_magnum_settings']['design']['design_footer']['footer_social']['social_acc_wrapper']['ft_sc_wrapper']['ft_sc_preview'][$key.'_closehtml'] = array(
                '#markup' => '<div class="preview-controls"><input class="remove form-submit" value="Remove"></div><div class="preview-demo"></div></li>'
            );
        }
    } else {
        $form['md_magnum_settings']['design']['design_footer']['footer_social']['social_acc_wrapper']['ft_sc_wrapper']['ft_sc_preview']['ft_sc_hidden_no1_openhtml'] = array(
            '#markup' => '<li id="ft-sc-sortable-no1" class="draggable-item sortable-item toggle-item" data-num="1" data-id="ft-sc-sortable-no1">'
        );
        $ft_sc_icon1 = theme_get_setting('ft_sc_icon_no1','md_magnum');
        $form['md_magnum_settings']['design']['design_footer']['footer_social']['social_acc_wrapper']['ft_sc_wrapper']['ft_sc_preview']['ft_sc_icon_no1'] = array(
            '#type' => 'icon_selector',
            '#title'    => 'Icon',
            '#default_bundle' => isset($ft_sc_icon1['bundle']) ? $ft_sc_icon1['bundle'] : '',
            '#default_icon' => $ft_sc_icon1['icon'],
            '#attributes'   => array(
                'class' => array('icon-select'),
                'id'    => array('ft-sc-no1')
            )
        );
        $form['md_magnum_settings']['design']['design_footer']['footer_social']['social_acc_wrapper']['ft_sc_wrapper']['ft_sc_preview']['ft_sc_link_no1'] = array(
            '#type' => 'textfield',
            '#title' => 'Icon Link',
            '#default_value'    => theme_get_setting('ft_sc_link_no1','md_magnum')
        );

        $form['md_magnum_settings']['design']['design_footer']['footer_social']['social_acc_wrapper']['ft_sc_wrapper']['ft_sc_preview']['ft_sc_hidden_no1_closehtml'] = array(
            '#markup' => '<div class="preview-controls"><input class="remove form-submit" value="Remove"></div><div class="preview-demo"></div></li>'
        );
    }
    $form['md_magnum_settings']['design']['design_footer']['footer_social']['social_acc_wrapper']['ft_sc_wrapper']['ft_sc_preview']["ft_sc_preview_closehtml"] = array(
        '#markup'   => '</ul>',
    );
    $form['md_magnum_settings']['design']['design_footer']['footer_content_wrapper'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="ft-content-wrapper">',
        '#suffix'   => '</div>'
    );
    $form['md_magnum_settings']['design']['design_footer']['footer_content_wrapper']['footer_text'] = array(
        '#type' => 'textarea',
        '#title'    => 'Footer Text Display',
        '#resizable'    => false,
        '#default_value'    => theme_get_setting('footer_text','md_magnum') ? theme_get_setting('footer_text','md_magnum') : 'Magnum™ design by
<a class="underline" target="blank" href="http://themeforest.net/user/Pixel-Stuff">PixelStuff</a>
- Drupal theme by
<a class="underline" target="blank" href="http://themeforest.net/user/megadrupal">MegaDrupal</a>
<br>
— Made with
<i class="fontello icon-heart text-color"></i>
on The Moon —'
    );

    $form['md_magnum_settings']['design']['design_nf'] = array(
        '#type' 					=> 'fieldset',
        '#weight' 				=> -9,
        '#prefix'  				=> '<div id="ds-nf" class="md-tabcontent clearfix">',
        '#suffix'        => '</div><!-- / #ds-general -->',
    );
    $form['md_magnum_settings']['design']['design_nf']['nf_background'] = array(
        '#type' => 'select',
        '#title'    => 'Choose background type of 404 page',
        '#options'  => array(
            'video' => 'Video Background',
            'custom'    => 'Custom Image Background',
        ),
        '#default_value'    => theme_get_setting('nf_background','md_magnum')
    );
    $form['md_magnum_settings']['design']['design_nf']['nf_custom_background'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="nf-custom-background">',
        '#suffix'   => '</div>',
    );

    $form['md_magnum_settings']['design']['design_nf']['nf_custom_background']['nf_video_bg'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="nf-video-bg">',
        '#suffix'   => '</div>',
    );
    $form['md_magnum_settings']['design']['design_nf']['nf_custom_background']['nf_video_bg']['nf_video_resolution'] =  array(
        '#type' => 'select',
        '#title'    => 'Choose Video Resolution',
        '#options'  => array(
            'default'   => 'Default',
            'medium'    => 'Medium',
            'small'     => 'Small',
            'large'     => 'Large',
            'hd720'     => 'Hd720',
            'hd1080'     => 'Hd1080',
            'highres'     => 'HighRes',
        ),
        '#default_value'    => theme_get_setting('nf_video_resolution','md_magnum'),
    );
    $form['md_magnum_settings']['design']['design_nf']['nf_custom_background']['nf_video_bg']['nf_video_link'] = array(
        '#type' => 'textfield',
        '#title'    => 'Custom Video Link',
        '#attributes' => array(
            'class' => array('nf-video-link'),
        ),
        '#default_value'    => theme_get_setting('nf_video_link','md_magnum'),
        '#maxlength' => 255,
    );
    $form['md_magnum_settings']['design']['design_nf']['nf_custom_background']['nf_video_bg']['nf_video_image_fallback'] = array(
        '#type' => 'textfield',
        '#title' => '<h3>Video Fallback Image</h3>',
        '#default_value' =>  theme_get_setting('nf_video_image_fallback','md_magnum'),
        '#description' => 'This image use for display when video stop, pause or display in mobile device',
        '#maxlength' => 255,
    );
    $form['md_magnum_settings']['design']['design_nf']['nf_custom_background']['nf_video_bg']['nf_video_image_fallback_upload'] = array(
        '#type' => 'file',
    );
    $form['md_magnum_settings']['design']['design_nf']['nf_custom_background']['nf_custom_image'] = array(
        '#type' => 'fieldset',
        '#prefix'  => '<div id="nf-custom-image">',
        '#suffix'   => '</div>'
    );
    $form['md_magnum_settings']['design']['design_nf']['nf_custom_background']['nf_custom_image']['nf_slide_effect'] = array(
        '#type' => 'select',
        '#prefix'   => '<div id="header-slide-effect">',
        '#suffix'   =>  '</div>',
        '#title'    => 'Choose Slide Image Effect',
        '#options'  => array(
            'linear' => 'Linear',
            'swing'   => 'Swing',
            'easeInQuad'   => 'easeInQuad',
            'easeOutQuad'  => 'easeOutQuad',
            'easeInOutQuad'  => 'easeInOutQuad',
            'easeInCubic'  => 'easeInCubic',
            'easeOutCubic'  => 'easeOutCubic',
            'easeInOutCubic'  => 'easeInOutCubic',
            'easeInQuart'  => 'easeInQuart',
            'easeOutQuart'  => 'easeOutQuart',
            'easeInOutQuart'  => 'easeInOutQuart',
            'easeInQuint'  => 'easeInQuint',
            'easeOutQuint'  => 'easeOutQuint',
            'easeInOutQuint'  => 'easeInOutQuint',
            'easeInExpo'  => 'easeInExpo',
            'easeOutExpo'  => 'easeOutExpo',
            'easeInOutExpo'  => 'easeInOutExpo',
            'easeInSine'  => 'easeInSine',
            'easeOutSine'  => 'easeOutSine',
            'easeInOutSine'  => 'easeInOutSine',
            'easeInCirc'  => 'easeInCirc',
            'easeOutCirc'  => 'easeOutCirc',
            'easeInBack'  => 'easeInBack',
            'easeOutBack'  => 'easeOutBack',
            'easeInOutBack'  => 'easeInOutBack',
        ),
        '#default_value'    => theme_get_setting('nf_slide_effect','md_magnum') ? theme_get_setting('nf_slide_effect','md_magnum') : 'fade',
        '#description' => 'Visit '.l('here','http://jqueryui.com/resources/demos/effect/easing.html').' for more detail. Some effect are removed for better display reason.',
    );
    $form['md_magnum_settings']['design']['design_nf']['nf_custom_background']['nf_custom_image']['nf_slide_delay'] = array(
        '#type' => 'textfield',
        '#title'    => 'Slide Timer Delay',
        '#default_value'    => theme_get_setting('nf_slide_delay','md_magnum') ? theme_get_setting('nf_slide_delay','md_magnum') : '4000',
        '#description' => 'Time to change each slide (milisecond)',
    );
    $form['md_magnum_settings']['design']['design_nf']['nf_custom_background']['nf_custom_image']['nf_slide_effect_time'] = array(
        '#type' => 'textfield',
        '#title'    => 'Effect time',
        '#default_value'    => theme_get_setting('nf_slide_effect_time','md_magnum') ? theme_get_setting('nf_slide_effect_time','md_magnum') : '1000',
        '#description' => 'Effect time when switching slide (milisecond)',
    );
    $form['md_magnum_settings']['design']['design_nf']['nf_custom_background']['nf_custom_image']['nf_image_slide_content_wrapper'] = array(
        '#type' => 'fieldset',
        '#prefix' => '<div id="nf-image-slide-wrapper">',
        '#suffix' => '</div>',
        '#attributes' => array(
            'class' => array('nf-image-slider-wrapper'),
        )
    );
    $max_num = theme_get_setting('nf_image_slide_max_num','md_magnum') ? theme_get_setting('nf_image_slide_max_num','md_magnum') : 1;
    $form['md_magnum_settings']['design']['design_nf']['nf_custom_background']['nf_custom_image']['nf_image_slide_content_wrapper']['nf_popup_add_wrapper'] = array(
        '#markup'   => '<a class="add-more" data-preview="nf_image_slide_preview" data-max-num="'.$max_num.'" href="#nf-image-slide-sortable-no'.$max_num.'">Add More</a>',
    );
    $form['md_magnum_settings']['design']['design_nf']['nf_custom_background']['nf_custom_image']['nf_image_slide_content_wrapper']['nf_popup_close_wrapper'] = array(
        '#markup' => '</div>'
    );
    $form['md_magnum_settings']['design']['design_nf']['nf_custom_background']['nf_custom_image']['nf_image_slide_content_wrapper']['nf_image_slide_preview'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="nf_image_slide_preview" class="data-container"><div class="popup-wrapper"></div>',
        '#sufix'    => '</div>'
    );
    $form['md_magnum_settings']['design']['design_nf']['nf_custom_background']['nf_custom_image']['nf_image_slide_content_wrapper']['nf_image_slide_order'] = array(
        '#type' => 'hidden',
        '#attributes' => array(
            'class'    => 'hidden-order'
        ),
    );
    $form['md_magnum_settings']['design']['design_nf']['nf_custom_background']['nf_custom_image']['nf_image_slide_content_wrapper']['nf_image_slide_max_num'] = array(
        '#type' => 'hidden',
        '#attributes' => array(
            'class'    => 'hidden-num'
        ),
        '#default_value' => theme_get_setting('nf_image_slide_max_num','md_magnum') ? theme_get_setting('nf_image_slide_max_num','md_magnum') : 1,
    );
    $form['md_magnum_settings']['design']['design_nf']['nf_custom_background']['nf_custom_image']['nf_image_slide_content_wrapper']['nf_image_slide_preview']["nf_image_slide_preview_openhtml"] = array(
        '#markup'   => '<ul id="nf_image_slide_sortable" class="sortable">'
    );
    if(theme_get_setting('nf_image_slide','md_magnum')) {
        $nf_image_slide = theme_get_setting('nf_image_slide','md_magnum');

        foreach($nf_image_slide as $key => $value) {
            $explode = explode("_",$key);
            end($explode);
            $num = current($explode);
            $form['md_magnum_settings']['design']['design_nf']['nf_custom_background']['nf_custom_image']['nf_image_slide_content_wrapper']['nf_image_slide_preview'][$key.'_openhtml'] = array(
                '#markup' => '<li id="nf-image-slide-sortable-'.$num.'" class="draggable-item sortable-item toggle-item" data-num="'.substr($num,2).'" data-id="nf-image-slide-sortable-no'.substr($num,2).'">'
            );
            $form['md_magnum_settings']['design']['design_nf']['nf_custom_background']['nf_custom_image']['nf_image_slide_content_wrapper']['nf_image_slide_preview'][$key]['nf_image_slide_path_'.$num.''] = array(
                '#type' => 'textfield',
                '#title' => t('Path to custom background image'),
                '#default_value' =>  $nf_image_slide[$key]['image'],
                '#prefix' => '<div>',
                '#maxlength' => 1000,
            );
            $form['md_magnum_settings']['design']['design_nf']['nf_custom_background']['nf_custom_image']['nf_image_slide_content_wrapper']['nf_image_slide_preview'][$key]['nf_image_slide_upload_'.$num.''] = array(
                '#type' => 'file',
                '#suffix' => '</div>'
            );

            $form['md_magnum_settings']['design']['design_nf']['nf_custom_background']['nf_custom_image']['nf_image_slide_content_wrapper']['nf_image_slide_preview'][$key.'_closehtml'] = array(
                '#markup' => '<div class="preview-controls"><input class="remove form-submit" value="Remove"></div><div class="preview-demo"></div></li>'
            );
        }
    } else {
        $form['md_magnum_settings']['design']['design_nf']['nf_custom_background']['nf_custom_image']['nf_image_slide_content_wrapper']['nf_image_slide_preview']['nf_image_slide_sortable_no1_openhtml'] = array(
            '#markup' => '<li id="nf-image-slide-sortable-no1" class="draggable-item sortable-item toggle-item" data-num="1" data-id="nf-image-slide-sortable-no1">'
        );
        $form['md_magnum_settings']['design']['design_nf']['nf_custom_background']['nf_custom_image']['nf_image_slide_content_wrapper']['nf_image_slide_preview']['nf_image_slide_path_no1'] = array(
            '#type' => 'textfield',
            '#title' => t('Path to custom background image'),
            '#default_value' =>  theme_get_setting('nf_image_slide_path_no1','md_magnum'),
            '#prefix' => '<div>',
            '#maxlength' => 1000,
        );
        $form['md_magnum_settings']['design']['design_nf']['nf_custom_background']['nf_custom_image']['nf_image_slide_content_wrapper']['nf_image_slide_preview']['nf_image_slide_upload_no1'] = array(
            '#type' => 'file',
            '#suffix' => '</div>'
        );
        $form['md_magnum_settings']['design']['design_nf']['nf_custom_background']['nf_custom_image']['nf_image_slide_content_wrapper']['nf_image_slide_preview']['nf_image_slide_sortable_no1_closehtml'] = array(
            '#markup' => '<div class="preview-controls"><input class="remove form-submit" value="Remove"></div><div class="preview-demo"></div></li>'
        );
    }
    $form['md_magnum_settings']['design']['design_nf']['nf_custom_background']['nf_custom_image']['nf_image_slide_content_wrapper']['nf_image_slide_preview']["nf_image_slide_preview_closehtml"] = array(
        '#markup'   => '</ul>'
    );

    $form['md_magnum_settings']['design']['design_nf']['nf_content'] = array(
        '#type' => 'fieldset',
        '#title'    => '<h3>404 Content</h3>'
    );
    $form['md_magnum_settings']['design']['design_nf']['nf_content']['nf_text'] = array(
        '#type' => 'textarea',
        '#title'    => '404 Text Display',
        '#default_value' => theme_get_setting('nf_text','md_magnum') ? theme_get_setting('nf_text','md_magnum') : "Oops! I couldn't find that one.<br>
    Click the button below to go back home.",
    );
    $form['md_magnum_settings']['design']['design_nf']['nf_content']['nf_button'] = array(
        '#type' => 'fieldset',
    );
    $icon_nf = theme_get_setting('nf_button_icon','md_magnum');
    $form['md_magnum_settings']['design']['design_nf']['nf_content']['nf_button']['nf_button_icon'] = array(
        '#type' => 'icon_selector',
        '#title'    => 'Button Icon',
        '#default_bundle' => isset($icon_nf['bundle']) ? $icon_nf['bundle'] : '',
        '#default_icon' => $icon_nf['icon'],
        '#attributes'   => array(
            'class' => array('icon-select'),
            'id'    => array('nf-fake'),
        )
    );
    $icon_css_inline = "";
    drupal_add_css($icon_css_inline,'inline');
    $form['md_magnum_settings']['design']['design_nf']['nf_content']['nf_button']['nf_icon_markup'] = array(
        '#markup' => ''
    );
    $form['md_magnum_settings']['design']['design_nf']['nf_content']['nf_button']['nf_button_text'] = array(
        '#type' => 'textfield',
        '#title'    => 'Button Text',
        '#default_value'    => theme_get_setting('nf_button_text','md_magnum') ? theme_get_setting('nf_button_text','md_magnum') : 'Home',
        '#maxlength' => 255,
    );
    $form['md_magnum_settings']['design']['design_nf']['nf_content']['nf_button']['nf_button_sub_text'] = array(
        '#type' => 'textfield',
        '#title'    => 'Button Sub Text',
        '#default_value'    => theme_get_setting('nf_button_sub_text','md_magnum') ? theme_get_setting('nf_button_sub_text','md_magnum') : 'Back to Business',
        '#maxlength' => 255,
    );
}



function md_magnum_prepare_parallax_form(&$form, $i) {
    global $base_url;
    $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_enabled'] = array(
        '#type'             => 'checkbox',
        '#title'            => t('Enable Parallax '.$i.''),
        '#default_value'    => theme_get_setting('parallax_'.$i.'_enabled','md_magnum'),
        '#suffix'           => '<div id="parallax-'.$i.'-custom">',
        '#attributes'   => array(
            'class' => array('enable-parallax'),
        )
    );
    $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_size'] = array(
        '#type' => 'select',
        '#title'    => 'Parallax Size',
        '#options'  => array(
            'big'   => 'Big',
            'medium' => 'Medium',
            'small' => 'Small',
            'custom'    => 'Custom'
        ),
        '#default_value'    => theme_get_setting('parallax_'.$i.'_size','md_magnum'),
    );
    $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_custom_size'] = array(
        '#type' => 'textfield',
        '#title'    => 'Custom Height',
        '#default_value'    => theme_get_setting('parallax_'.$i.'_custom_size','md_magnum'),
        '#field_suffix' => 'px',
        '#prefix'   => '<div class="pr-size">',
        '#suffix'   => '</div>'
    );
    $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_background'] = array(
        '#type' => 'fieldset',

        '#prefix'   => '<div id="parallax-'.$i.'-background">',
        "#suffix"   => '</div>',
    );
    $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_background']['parallax_'.$i.'_background_type'] = array(
        '#type' => 'select',
        '#title'    => 'Choose background type',
        '#options'  => array(
            'global'    => 'Global (Same header background type)',
            'custom'    => 'Custom Image Background',
            'video'     => ' Custom Video Background (only support youtube)',
            'pattern'   => 'Pattern Background',
            'color' => 'Single Color Background',
        ),
        '#default_value'    => theme_get_setting('parallax_'.$i.'_background_type','md_magnum'),
        '#attributes'   => array(
            'class' => array('pr-background-type')
        )
    );
    $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_background']['pr'.$i.'_pattern_bg'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="pr'.$i.'-pattern-bg" class="pr-pattern-bg">',
        '#suffix' => '</div>',
    );
    $items = array();
    $path_data_dir = drupal_get_path('theme', 'md_magnum') . '/images/background/patterns';
    $files = file_scan_directory($path_data_dir, '/.png$/');
    $pattern_css = "";
    foreach ($files as $file) {
        $items[$file->name] = t('Pattern ' . $file->name);
        $pattern_css .= '#pr'.$i.'pt'.$file->name.' {background:url(' . $base_url .'/'. drupal_get_path('theme', 'md_magnum') . '/images/background/patterns/' . $file->name . '.png) repeat 0 0;}';
    }
    drupal_add_css($pattern_css, 'inline');


    $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_background']['pr'.$i.'_pattern_bg']['choose_pr'.$i.'_pattern'] = array(
        '#type'          => 'select',
        '#title'         => t('Choose Pattern'),
        '#default_value' => theme_get_setting('choose_pr'.$i.'_pattern','md_magnum'),
        '#options'       => $items,
        '#prefix' => '<div id="design-pr'.$i.'-bg-pattern" class="clearfix">',
        '#suffix' => '</div>',
    );
    $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_background']['pr'.$i.'_color_bg'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="pr'.$i.'-color-bg" class="pr-color-bg">',
        '#suffix' => '</div>',
    );
    $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_background']['pr'.$i.'_color_bg']['pr'.$i.'_bg_color'] = array(
        '#type'          => 'textfield',
        '#title'         => t('Background-color'),
        '#default_value' => theme_get_setting('pr'.$i.'_bg_color','md_magnum'),
        '#prefix' => '<div class="form-font-color">',
        '#suffix' => '</div>'
    );
    $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_background']['video_'.$i.'_wrapper'] = array(
        '#type' => 'fieldset',
        '#title' => 'Custom Video Background',
        '#prefix' => '<div id="custom-video-wrapper"><div id="vd'.$i.'-wrapper" >',
        '#suffix' => '</div></div>',
        '#attributes' => array(
            'class' => array('video-wrapper'),
        )
    );
    $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_background']['video_'.$i.'_wrapper']['pr'.$i.'_video_resolution'] =  array(
        '#type' => 'select',
        '#title'    => 'Choose Video Resolution',
        '#options'  => array(
            'default'   => 'Default',
            'medium'    => 'Medium',
            'small'     => 'Small',
            'large'     => 'Large',
            'hd720'     => 'Hd720',
            'hd1080'     => 'Hd1080',
            'highres'     => 'HighRes',
        ),
        '#default_value'    => theme_get_setting('pr'.$i.'_video_resolution','md_magnum'),
    );
    $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_background']['video_'.$i.'_wrapper']['pr'.$i.'_video_link'] = array(
        '#type' => 'textfield',
        '#title'    => 'Custom Video Link',
        '#attributes' => array(
            'class' => array('video_link'),
        ),
        '#default_value'    => theme_get_setting('pr'.$i.'_video_link','md_magnum'),
        '#maxlength' => 255,
    );
    $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_background']['slide_'.$i.'_wrapper'] = array(
        '#type' => 'fieldset',
        '#title' => 'Custom background image',
        '#prefix' => '<div id="custom-bg-wrapper"><div id="sd'.$i.'-slide-wrapper" >',
        '#suffix' => '</div>',
        '#attributes' => array(
            'class' => array('slide-wrapper'),
        )
    );
    $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_background']['slide_'.$i.'_wrapper']['pr'.$i.'_slide_effect'] = array(
        '#type' => 'select',
        '#prefix'   => '<div id="parallax-slide-effect">',
        '#suffix'   =>  '</div>',
        '#title'    => 'Choose Slide Image Effect',
        '#options'  => array(
            'linear' => 'Linear',
            'swing'   => 'Swing',
            'easeInQuad'   => 'easeInQuad',
            'easeOutQuad'  => 'easeOutQuad',
            'easeInOutQuad'  => 'easeInOutQuad',
            'easeInCubic'  => 'easeInCubic',
            'easeOutCubic'  => 'easeOutCubic',
            'easeInOutCubic'  => 'easeInOutCubic',
            'easeInQuart'  => 'easeInQuart',
            'easeOutQuart'  => 'easeOutQuart',
            'easeInOutQuart'  => 'easeInOutQuart',
            'easeInQuint'  => 'easeInQuint',
            'easeOutQuint'  => 'easeOutQuint',
            'easeInOutQuint'  => 'easeInOutQuint',
            'easeInExpo'  => 'easeInExpo',
            'easeOutExpo'  => 'easeOutExpo',
            'easeInOutExpo'  => 'easeInOutExpo',
            'easeInSine'  => 'easeInSine',
            'easeOutSine'  => 'easeOutSine',
            'easeInOutSine'  => 'easeInOutSine',
            'easeInCirc'  => 'easeInCirc',
            'easeOutCirc'  => 'easeOutCirc',
            'easeInBack'  => 'easeInBack',
            'easeOutBack'  => 'easeOutBack',
            'easeInOutBack'  => 'easeInOutBack',
        ),
        '#default_value'    => theme_get_setting('pr'.$i.'_slide_effect','md_magnum') ? theme_get_setting('pr'.$i.'_slide_effect','md_magnum') : 'fade',
        '#description' => 'Visit '.l('here','http://jqueryui.com/resources/demos/effect/easing.html').' for more detail. Some effect are removed for better display reason.',
    );
    $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_background']['slide_'.$i.'_wrapper']['pr'.$i.'_slide_delay'] = array(
        '#type' => 'textfield',
        '#title'    => 'Slide Timer Delay',
        '#default_value'    => theme_get_setting('pr'.$i.'_slide_delay','md_magnum') ? theme_get_setting('pr'.$i.'_slide_delay','md_magnum') : '4000',
        '#description' => 'Time to change each slide (milisecond)',
    );
    $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_background']['slide_'.$i.'_wrapper']['pr'.$i.'_slide_effect_time'] = array(
        '#type' => 'textfield',
        '#title'    => 'Effect time',
        '#default_value'    => theme_get_setting('pr'.$i.'_slide_effect_time','md_magnum') ? theme_get_setting('pr'.$i.'_slide_effect_time','md_magnum') : '1000',
        '#description' => 'Effect time when switching slide (milisecond)',
    );

    $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_background']['slide_'.$i.'_wrapper']['pr_'.$i.'_image_slide_wrapper'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="pr-'.$i.'-image-slide-wrapper" class="pr-image-slide--wrapper"><h3>Parallax Image Slide</h3>',
        '#suffix'   => '</div>'
    );
    $max_num = theme_get_setting('pr_'.$i.'_image_slide_max_num','md_magnum') ? theme_get_setting('pr_'.$i.'_image_slide_max_num','md_magnum') : 1;
    $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_background']['slide_'.$i.'_wrapper']['pr_'.$i.'_image_slide_wrapper']['pr_'.$i.'_popup_add_wrapper'] = array(
        '#markup'   => '<a class="add-more" data-preview="pr_'.$i.'_image_slide_preview" data-max-num="'.$max_num.'" href="#pr-'.$i.'-image-slide-sortable-no'.$max_num.'">Add More</a>',
    );
    $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_background']['slide_'.$i.'_wrapper']['pr_'.$i.'_image_slide_wrapper']['pr_'.$i.'_popup_close_wrapper'] = array(
        '#markup' => '</div>'
    );
    $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_background']['slide_'.$i.'_wrapper']['pr_'.$i.'_image_slide_wrapper']['pr_'.$i.'_image_slide_preview'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="pr_'.$i.'_image_slide_preview" class="data-container"><div class="popup-wrapper"></div>',
        '#sufix'    => '</div>'
    );
    $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_background']['slide_'.$i.'_wrapper']['pr_'.$i.'_image_slide_wrapper']['pr_'.$i.'_image_slide_order'] = array(
        '#type' => 'hidden',
        '#attributes' => array(
            'class'    => 'hidden-order'
        ),
    );
    $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_background']['slide_'.$i.'_wrapper']['pr_'.$i.'_image_slide_wrapper']['pr_'.$i.'_image_slide_max_num'] = array(
        '#type' => 'hidden',
        '#attributes' => array(
            'class'    => 'hidden-num'
        ),
        '#default_value' => theme_get_setting('pr_'.$i.'_image_slide_max_num','md_magnum') ? theme_get_setting('pr_'.$i.'_image_slide_max_num','md_magnum') : 1,
    );
    $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_background']['slide_'.$i.'_wrapper']['pr_'.$i.'_image_slide_wrapper']['pr_'.$i.'_image_slide_preview']["pr_'.$i.'_image_slide_preview_openhtml"] = array(
        '#markup'   => '<ul id="pr_'.$i.'_image_slide_sortable" class="sortable">'
    );

    if(theme_get_setting('pr_'.$i.'_image_slide','md_magnum') && count(theme_get_setting('pr_'.$i.'_image_slide','md_magnum')) > 1) {
        $slide = theme_get_setting('pr_'.$i.'_image_slide','md_magnum');
        foreach($slide as $key => $value) {
            $explode = explode("_",$key);
            end($explode);
            $num = current($explode);
            $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_background']['slide_'.$i.'_wrapper']['pr_'.$i.'_image_slide_wrapper']['pr_'.$i.'_image_slide_preview'][$key.'_openhtml'] = array(
                '#markup' => '<li id="pr-'.$i.'-image-slide-sortable-'.$num.'" class="draggable-item sortable-item toggle-item" data-num="'.substr($num,2).'" data-id="pr-'.$i.'-image-slide-sortable-no'.substr($num,2).'">'
            );
            $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_background']['slide_'.$i.'_wrapper']['pr_'.$i.'_image_slide_wrapper']['pr_'.$i.'_image_slide_preview'][$key]['pr_'.$i.'_image_slide_path_'.$num.''] = array(
                '#type' => 'textfield',
                '#title' => t('Path to custom background image'),
                '#default_value' =>  $slide[$key]['image'],
                '#prefix' => '<div class="md-updateimage">',
                '#maxlength' => 10000,
            );
            $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_background']['slide_'.$i.'_wrapper']['pr_'.$i.'_image_slide_wrapper']['pr_'.$i.'_image_slide_preview'][$key]['pr_'.$i.'_image_slide_upload_'.$num.''] = array(
                '#type' => 'file',
                '#suffix' => '</div>'
            );
            $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_background']['slide_'.$i.'_wrapper']['pr_'.$i.'_image_slide_wrapper']['pr_'.$i.'_image_slide_preview'][$key.'_closehtml'] = array(
                '#markup' => '<div class="preview-controls"><input class="remove form-submit" value="Remove"><div class="preview-demo"></div></li>'
            );
        }
    } else {
        $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_background']['slide_'.$i.'_wrapper']['pr_'.$i.'_image_slide_wrapper']['pr_'.$i.'_image_slide_preview']['pr_'.$i.'_image_slide_hidden_no1_openhtml'] = array(
            '#markup' => '<li id="pr-'.$i.'-image-slide-sortable-no1" class="draggable-item sortable-item toggle-item" data-num="1" data-id="pr-'.$i.'-image-slide-sortable-no1">'
        );
        $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_background']['slide_'.$i.'_wrapper']['pr_'.$i.'_image_slide_wrapper']['pr_'.$i.'_image_slide_preview']['pr_'.$i.'_image_slide_path_no1'] = array(
            '#type' => 'textfield',
            '#title' => t('Path to custom background image'),
            '#default_value' => theme_get_setting('pr_'.$i.'_image_slide_path_no1','md_magnum'),
            '#prefix' => '<div class="md-updateimage">',
            '#maxlength' => 10000,
        );
        $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_background']['slide_'.$i.'_wrapper']['pr_'.$i.'_image_slide_wrapper']['pr_'.$i.'_image_slide_preview']['pr_'.$i.'_image_slide_upload_no1'] = array(
            '#type' => 'file',
            '#suffix' => '</div>'

        );
        $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_background']['slide_'.$i.'_wrapper']['pr_'.$i.'_image_slide_wrapper']['pr_'.$i.'_image_slide_preview']['pr_'.$i.'_image_slide_hidden_no1_closehtml'] = array(
            '#markup' => '<div class="preview-controls"><input class="remove form-submit" value="Remove"></div><div class="preview-demo"></div></li>'
        );
    }
    $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_background']['slide_'.$i.'_wrapper']['pr_'.$i.'_image_slide_wrapper']['pr_'.$i.'_image_slide_preview']["pr_'.$i.'_image_slide_preview_closehtml"] = array(
        '#markup'   => '</ul>',
    );
    $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_content'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="parallax-'.$i.'-content">',
        "#suffix"   => '</div>',
    );
    $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_content']['pr_'.$i.'_content_display'] = array(
        '#type' => 'select',
        '#title'    => t('Choose type of content display'),
        '#options'  => array(
            'text'    => t('Text'),
            'text_link'    => t('Text & Link'),
        ),
        '#default_value' => theme_get_setting('pr_'.$i.'_content_display','md_magnum'),
        '#attributes' => array(
            'class' => array('parallax-content-type'),
        ),
    );
    $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_content']['pr'.$i.'_text_display'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="pr-'.$i.'-ct-text-wrapper" class="pr-ct-text-wrapper"><h3>Parallax Content Text Display</h3>',
        '#suffix'   => '</div>'
    );
    $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_content']['pr'.$i.'_text_display']['pr'.$i.'_text_slide_delay_time'] = array(
        '#type' => 'textfield',
        '#title'    => 'Delay time for text/quote slide (milisecond)',
        '#default_value'    => theme_get_setting('pr'.$i.'_text_slide_delay_time','md_magnum') ? theme_get_setting('pr'.$i.'_text_slide_delay_time','md_magnum') : '7000'
    );
    $max_num = theme_get_setting('pr_'.$i.'_ct_text_max_num','md_magnum') ? theme_get_setting('pr_'.$i.'_ct_text_max_num','md_magnum') : 1;
    $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_content']['pr'.$i.'_text_display']['pr_'.$i.'_ct_text_wrapper']['pr_'.$i.'_popup_add_wrapper'] = array(
        '#markup'   => '<a class="add-more" data-preview="pr_'.$i.'_ct_text_preview" data-max-num="'.$max_num.'" href="#pr-'.$i.'-ct-text-sortable-no'.$max_num.'">Add More</a>',
    );
    $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_content']['pr'.$i.'_text_display']['pr_'.$i.'_ct_text_wrapper']['pr_'.$i.'_popup_close_wrapper'] = array(
        '#markup' => '</div>'
    );
    $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_content']['pr'.$i.'_text_display']['pr_'.$i.'_ct_text_wrapper']['pr_'.$i.'_ct_text_preview'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="pr_'.$i.'_ct_text_preview" class="data-container"><div class="popup-wrapper"></div>',
        '#sufix'    => '</div>'
    );
    $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_content']['pr'.$i.'_text_display']['pr_'.$i.'_ct_text_wrapper']['pr_'.$i.'_ct_text_order'] = array(
        '#type' => 'hidden',
        '#attributes' => array(
            'class'    => 'hidden-order'
        ),
    );
    $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_content']['pr'.$i.'_text_display']['pr_'.$i.'_ct_text_wrapper']['pr_'.$i.'_ct_text_max_num'] = array(
        '#type' => 'hidden',
        '#attributes' => array(
            'class'    => 'hidden-num'
        ),
        '#default_value' => theme_get_setting('pr_'.$i.'_ct_text_max_num','md_magnum') ? theme_get_setting('pr_'.$i.'_ct_text_max_num','md_magnum') : 1,
    );
    $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_content']['pr'.$i.'_text_display']['pr_'.$i.'_ct_text_wrapper']['pr_'.$i.'_ct_text_preview']["pr_'.$i.'_ct_text_preview_openhtml"] = array(
        '#markup'   => '<ul id="pr_'.$i.'_ct_text_sortable" class="sortable">'
    );

    if(theme_get_setting('pr_'.$i.'_ct_text','md_magnum') && count(theme_get_setting('pr_'.$i.'_ct_text','md_magnum')) > 1) {
        $slide = theme_get_setting('pr_'.$i.'_ct_text','md_magnum');
        foreach($slide as $key => $value) {
            $explode = explode("_",$key);
            end($explode);
            $num = current($explode);
            $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_content']['pr'.$i.'_text_display']['pr_'.$i.'_ct_text_wrapper']['pr_'.$i.'_ct_text_preview'][$key.'_openhtml'] = array(
                '#markup' => '<li id="pr-'.$i.'-ct-text-sortable-'.$num.'" class="draggable-item sortable-item toggle-item" data-num="'.substr($num,2).'" data-id="pr-'.$i.'-ct-text-sortable-no'.substr($num,2).'">'
            );
            $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_content']['pr'.$i.'_text_display']['pr_'.$i.'_ct_text_wrapper']['pr_'.$i.'_ct_text_preview'][$key]['pr_'.$i.'_ct_text_title_'.$num.''] = array(
                '#type' => 'textfield',
                '#title' => t('Title'),
                '#default_value' =>  $slide[$key]['title'],
                '#maxlength' => 10000,
            );
            $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_content']['pr'.$i.'_text_display']['pr_'.$i.'_ct_text_wrapper']['pr_'.$i.'_ct_text_preview'][$key]['pr_'.$i.'_ct_text_sub_title_'.$num.''] = array(
                '#type' => 'textfield',
                '#title' => t('Sub Title'),
                '#default_value' =>  $slide[$key]['sub_title'],
                '#maxlength' => 10000,
            );
            $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_content']['pr'.$i.'_text_display']['pr_'.$i.'_ct_text_wrapper']['pr_'.$i.'_ct_text_preview'][$key.'_closehtml'] = array(
                '#markup' => '<div class="preview-controls"><input class="remove form-submit" value="Remove"></div><div class="preview-demo"></div></li>'
            );
        }
    } else {
        $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_content']['pr'.$i.'_text_display']['pr_'.$i.'_ct_text_wrapper']['pr_'.$i.'_ct_text_preview']['pr_'.$i.'_ct_text_hidden_no1_openhtml'] = array(
            '#markup' => '<li id="pr-'.$i.'-ct-text-sortable-no1" class="draggable-item sortable-item toggle-item" data-num="1" data-id="pr-'.$i.'-ct-text-sortable-no1">'
        );
        $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_content']['pr'.$i.'_text_display']['pr_'.$i.'_ct_text_wrapper']['pr_'.$i.'_ct_text_preview']['pr_'.$i.'_ct_text_title_no1'] = array(
            '#type' => 'textfield',
            '#title' => t('Title'),
            '#default_value' => theme_get_setting('pr_'.$i.'_ct_text_title_no1','md_magnum'),
            '#maxlength' => 10000,
        );
        $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_content']['pr'.$i.'_text_display']['pr_'.$i.'_ct_text_wrapper']['pr_'.$i.'_ct_text_preview']['pr_'.$i.'_ct_text_sub_title_no1'] = array(
            '#type' => 'textfield',
            '#title' => t('Sub Title'),
            '#default_value' =>  theme_get_setting('pr_'.$i.'_ct_text_sub_title_no1','md_magnum'),
            '#maxlength' => 10000,
        );
        $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_content']['pr'.$i.'_text_display']['pr_'.$i.'_ct_text_wrapper']['pr_'.$i.'_ct_text_preview']['pr_'.$i.'_ct_text_hidden_no1_closehtml'] = array(
            '#markup' => '<div class="preview-controls"><input class="remove form-submit" value="Remove"></div><div class="preview-demo"></div></li>'
        );
    }
    $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_content']['pr'.$i.'_text_display']['pr_'.$i.'_ct_text_wrapper']['pr_'.$i.'_ct_text_preview']["pr_'.$i.'_ct_text_preview_closehtml"] = array(
        '#markup'   => '</ul>',
    );

    $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_content']['pr'.$i.'_text_link_display'] = array(
        '#type' => 'fieldset',
        '#prefix'   => '<div id="pr'.$i.'-text-link-display" class="pr-text-link-display">',
        "#suffix"   => '</div>',
    );

    $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_content']['pr'.$i.'_text_link_display']['pr'.$i.'_tl_text_display'] = array(
        '#type' => 'textfield',
        '#title'    => 'Big Text Display',
        '#attributes' => array(
            'class' => array('pr_tl_text'),
        ),
        '#default_value'    => theme_get_setting('pr'.$i.'_tl_text_display','md_magnum'),
        '#maxlength' => 10000,
    );
    $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_content']['pr'.$i.'_text_link_display']['pr'.$i.'_tl_link_display'] = array(
        '#type' => 'fieldset',
        '#title' => '<h3>Custom button</h3>',
        '#prefix'   => '<div id="pr'.$i.'-tl-link">',
        "#suffix"   => '</div>',
    );
    $default_icon = theme_get_setting('pr'.$i.'_tl_bt_icon','md_magnum');
    $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_content']['pr'.$i.'_text_link_display']['pr'.$i.'_tl_link_display']['pr'.$i.'_tl_bt_icon'] = array(
        '#type' => 'icon_selector',
        '#title' => 'Button Icon',
        '#default_bundle' => isset($default_icon['bundle']) ? $default_icon['bundle'] : '',
        '#default_icon' => $default_icon['icon'],
        '#attributes'   => array(
            'class' => array('icon-select'),
            'id'    => array('pr'.$i.'-fake')
        ),
    );
    $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_content']['pr'.$i.'_text_link_display']['pr'.$i.'_tl_link_display']['pr'.$i.'_tl_bt_title'] = array(
        '#type' => 'textfield',
        '#title'    => 'Button Title',
        '#default_value'    => theme_get_setting('pr'.$i.'_tl_bt_title','md_magnum') ? theme_get_setting('pr'.$i.'_tl_bt_title','md_magnum') : 'Lets get in touch' ,
        '#maxlength' => 10000,
    );
    $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_content']['pr'.$i.'_text_link_display']['pr'.$i.'_tl_link_display']['pr'.$i.'_tl_bt_link'] = array(
        '#type' => 'textfield',
        '#title'    => 'Button Link',
        '#default_value'    => theme_get_setting('pr'.$i.'_tl_bt_link','md_magnum') ? theme_get_setting('pr'.$i.'_tl_bt_link','md_magnum') : '#contact' ,
        '#maxlength' => 10000,
    );

    $form['md_magnum_settings']['design']['design_parallax']['parallax_'.$i.'']['parallax_'.$i.'_enable_close'] = array(
        '#markup' 				=> '</div>'
    );
}