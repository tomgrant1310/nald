<?php
/**
 * Add body classes if certain regions have content.
 */
function md_magnum_preprocess_html(&$vars) {
    global $base_url;
    $css = "";
    $themepath = drupal_get_path('theme', 'md_magnum');
    if(module_exists('icon') && module_exists('fontello')) {
        $icon_bundles = icon_bundles();
        foreach($icon_bundles as $key => $value) {
            if($value['status'] == 1) {
                fontello_process_attached($key);
            }
        }
    }
    drupal_add_css($themepath . '/css/loader.css');
    drupal_add_css($themepath . '/css/lib/essentials.css');
    drupal_add_css($themepath . '/css/lib/backslider.css');
    drupal_add_css($themepath . '/css/lib/ytplayer.css');
    drupal_add_css($themepath . '/css/lib/magnific-popup.css');
    drupal_add_css($themepath . '/css/lib/jquery.bxslider.css');
    drupal_add_css($themepath . '/css/lib/flexslider.css');
    drupal_add_css($themepath . '/css/style.css');
    $skin = theme_get_setting('skins','md_magnum');
    drupal_add_css($themepath . '/css/colors/'.$skin.'.css');

    drupal_add_js($themepath . '/js/lib/modernizr.js');
    drupal_add_js($themepath . '/js/lib/jquery.equal.js');
    drupal_add_js($themepath . '/js/lib/jquery.fittext.js');
    drupal_add_js($themepath . '/js/lib/jquery.magnific-popup.min.js');
    drupal_add_js($themepath . '/js/lib/jquery.bxslider.min.js');
    drupal_add_js($themepath . '/js/lib/jquery.flexslider.js');
    drupal_add_js($themepath . '/js/lib/jquery.easing.js');
    drupal_add_js($themepath . '/js/lib/jquery.backslider.js');
    drupal_add_js($themepath . '/js/lib/jquery.sticky.js');
    drupal_add_js($themepath . '/js/lib/jquery.ytplayer.js');
    drupal_add_js($themepath . '/js/lib/jquery.touchswipe.min.js');
    drupal_add_js($themepath . '/js/lib/jquery.caroufredsel.min.js');
    drupal_add_js($themepath . '/js/services-slider.js');
    drupal_add_js($themepath . '/js/main.js',array('scope' => 'footer'));
    /* ------------------------- Blog Page ------------------------*/

    if(in_array('node-type-blog',$vars['classes_array'])) {
        $vars['classes_array'][] = 'blog-page';
    }

    /* ---------------------------------------------- Skin  ---------------------------------------------------------*/
    if (theme_get_setting('skins') != '0') {
        drupal_add_css($themepath . '/css/colors/'.theme_get_setting('skins').'.css', array('group' => CSS_THEME));
    }
    /* ----------------------------------------------- Menu ---------------------------------------------------------*/
    if(theme_get_setting('menu_sticky','md_magnum')) {
        drupal_add_js(array('menuStickyEnable' => theme_get_setting('menu_sticky','md_magnum')),'setting');
    }
    if(theme_get_setting('menu_bg_color','md_magnum')) {
        $css .= '.main-menu {background-color: #'.theme_get_setting('menu_bg_color','md_magnum').'}'."\n";
    }
    if(theme_get_setting('menu_link_color','md_magnum')) {
        $css .= '.menu-nav li a {color: #'.theme_get_setting('menu_link_color','md_magnum').'}'."\n";
    }
    if(theme_get_setting('menu_link_hover_color','md_magnum')) {
        $css .= '.menu-nav li a:hover {color: #'.theme_get_setting('menu_link_hover_color','md_magnum').'}'."\n";
    }
    /* ---------------------------------------------- Header -----------------------------------------------------*/
    $header_bg_type = theme_get_setting('header_background_type','md_magnum');
    drupal_add_js(array('hdBgType' => $header_bg_type),'setting');
    if($header_bg_type == 'custom') {
        if(theme_get_setting('header_slide_effect','md_magnum')) {
            drupal_add_js(array('hdSlideEffect' => theme_get_setting('header_slide_effect','md_magnum')),'setting');
            drupal_add_js(array('hdSlideDelay' => theme_get_setting('header_slide_delay','md_magnum')),'setting');
            drupal_add_js(array('hdEffectTime' => theme_get_setting('header_slide_effect_time','md_magnum')),'setting');
        }
    }
    if($header_bg_type == 'video') {
        if(theme_get_setting('header_video_play','md_magnum') == 1) {
            drupal_add_js(array('headerVideoAutoPlay' => true),'setting');
        } else {
            drupal_add_js(array('headerVideoAutoPlay' => false),'setting');
        }
        if(theme_get_setting('header_video_resolution','md_magnum')){
            $hd_video_res = theme_get_setting('header_video_resolution','md_magnum');
            drupal_add_js(array('headerVideoRes' => $hd_video_res),'setting');
        }
    }
    if(theme_get_setting('header_size','md_magnum') == 'custom') {
        if(theme_get_setting('header_custom_height','md_magnum')) {
            $css .= '#home { height:'.theme_get_setting('header_size','md_magnum').'px;}'."\n";
        }
    }

    /* ----------------------- Normal Parallax  --------------------------*/
    for($i=1;$i<=3;$i++){
    $pr_bg_type = theme_get_setting('parallax_'.$i.'_background_type');
        drupal_add_js(array('pr'.$i.'BgType' => $pr_bg_type),'setting');
        /* ------------------------ Parallax Background Image ----------------------------*/
        if($pr_bg_type == 'video') {
            if(theme_get_setting('pr'.$i.'_video_resolution','md_magnum')){
                $pr_video_res = theme_get_setting('pr'.$i.'_video_resolution','md_magnum');
                drupal_add_js(array('pr'.$i.'VideoRes' => $pr_video_res),'setting');
            }
        }
        if(theme_get_setting('parallax_'.$i.'_background_type') == 'custom') {
            if($slide = theme_get_setting('sd'.$i.'_slide')) {
                if(theme_get_setting('pr'.$i.'_slide_effect','md_magnum')) {
                    drupal_add_js(array('pr'.$i.'SlideEffect' => theme_get_setting('pr'.$i.'_slide_effect','md_magnum')),'setting');
                    drupal_add_js(array('pr'.$i.'SlideDelay' => theme_get_setting('pr'.$i.'_slide_delay','md_magnum')),'setting');
                    drupal_add_js(array('pr'.$i.'EffectTime' => theme_get_setting('pr'.$i.'_slide_effect_time','md_magnum')),'setting');
                }
            }
        }
        if(theme_get_setting('parallax_'.$i.'_background_type') == 'global') {
            $css .= '#pr'.$i.'-slider { background:none; }'."\n";
        }
        if($pr_bg_type == 'pattern') {
            $css .= "#parallax-".$i." .header{ background:url(" . $base_url .'/'. $themepath ."/images/background/patterns/". theme_get_setting('choose_pr'.$i.'_pattern','md_magnum') . ".png) repeat 0 0;}\n";
        }
        if($pr_bg_type == 'color') {
            $css .= '#parallax-'.$i.' .header{ background: none repeat scroll 0 0 #'.theme_get_setting('pr'.$i.'_bg_color','md_magnum').';}'."\n";
        }
        if(theme_get_setting('parallax_'.$i.'_size') == 'custom') {
            if(theme_get_setting('parallax_'.$i.'_custom_size')) {
                $css .= '#parallax-'.$i.' { height: '.theme_get_setting('parallax_'.$i.'_custom_size').'px;}'."\n";
            }
        }
        // Parallax Text Slide Delay Time
        if(theme_get_setting('pr'.$i.'_text_slide_delay_time','md_magnum')) {
            drupal_add_js(array('pr_'.$i.'_text_slide_delay_time' => theme_get_setting('pr'.$i.'_text_slide_delay_time','md_magnum')),'setting');
        }
    }
    /* ---------------------------------------------- Footer -----------------------------------------------------*/
    $footer_bg_type = theme_get_setting('footer_background','md_magnum');
    $ft_content_display = theme_get_setting('footer_content_display','md_magnum');
    drupal_add_js(array('ftBgType' => $footer_bg_type),'setting');
    if($footer_bg_type == 'video') {
        if(theme_get_setting('ft_video_resolution','md_magnum')){
            $ft_video_res = theme_get_setting('ft_video_resolution','md_magnum');
            drupal_add_js(array('ftVideoRes' => $ft_video_res),'setting');
        }
    }
    if($footer_bg_type == 'color'){
        if($ft_content_display == '1') {
            $css .= '.footer-two { background: none repeat scroll 0 0 #'.theme_get_setting('ft_bg_color','md_magnum').';}'."\n";
        }
        if($ft_content_display == '2') {
            $css .= '.footer { background: none repeat scroll 0 0 #'.theme_get_setting('ft_bg_color','md_magnum').';}'."\n";
        }
    }
    if($footer_bg_type == 'pattern') {
        if($ft_content_display == '1') {
            $css .= ".footer-two {background:url(" . $base_url .'/'. $themepath ."/images/background/patterns/". theme_get_setting('choose_ft_pattern','md_magnum') . ".png) repeat 0 0;}\n";
        }
        if($ft_content_display == '2') {
            $css .= ".footer {background:url(" . $base_url .'/'. $themepath ."/images/background/patterns/". theme_get_setting('choose_ft_pattern','md_magnum') . ".png) repeat 0 0;}\n";
        }
    }
    if($footer_bg_type == 'custom') {
        if(theme_get_setting('footer_slide_effect','md_magnum')) {
            drupal_add_js(array('ftSlideEffect' => theme_get_setting('footer_slide_effect','md_magnum')),'setting');
            drupal_add_js(array('ftSlideDelay' => theme_get_setting('footer_slide_delay','md_magnum')),'setting');
            drupal_add_js(array('ftEffectTime' => theme_get_setting('footer_slide_effect_time','md_magnum')),'setting');
        }
    }
    /* ---------------------------------------------- 404 Page -----------------------------------------------------*/
    $nf_bg_type = theme_get_setting('nf_background','md_magnum');
    drupal_add_js(array('nfBgType' => $nf_bg_type),'setting');
    if($nf_bg_type == 'video') {
        if(theme_get_setting('nf_video_resolution','md_magnum')){
            $ft_video_res = theme_get_setting('nf_video_resolution','md_magnum');
            drupal_add_js(array('nfVideoRes' => $ft_video_res),'setting');
        }
    }
    if($nf_bg_type == 'custom') {
        if(theme_get_setting('nf_slide_effect','md_magnum')) {
            drupal_add_js(array('nfSlideEffect' => theme_get_setting('nf_slide_effect','md_magnum')),'setting');
            drupal_add_js(array('nfSlideDelay' => theme_get_setting('nf_slide_delay','md_magnum')),'setting');
            drupal_add_js(array('nfEffectTime' => theme_get_setting('nf_slide_effect_time','md_magnum')),'setting');
        }

    }
    $vars['theme_setting_css'] = $css;
	// Custom Web clip
	$webclip_path = theme_get_setting('webclip_path','md_magnum');
	if ($webclip_path) {
    $wc_href = "";
		if (file_uri_scheme($webclip_path) == 'public') {
			$wc_href = file_create_url($webclip_path);
		} else {
			$wc_href = file_create_url(file_build_uri($webclip_path));
		}

		$wc_rel = "apple-touch-icon";
	  if (theme_get_setting('webclip_precomp','md_magnum')) { // no output if $url_precomp = ''
	    $wc_rel = "apple-touch-icon-precomposed";
	  }
		$wc = array(
			'#tag' => 'link',
			'#attributes' => array(
				'href' => $wc_href,
				'rel' => $wc_rel,
				'type' => file_get_mimetype($wc_href),
			),
		);
		drupal_add_html_head($wc, 'webclip');
	}

	// Enable Responsive
	if (theme_get_setting('responsive','md_magnum')) {
		$menuid = 'main-menu';
		if (!empty($vars['page']['superfish'])) {
			$tmp_array_keys = array_keys($vars['page']['superfish']);
			$menuid = str_replace("_","-",$tmp_array_keys[0]);
		}
		$selecnav = '(function ($) {
			$(function(){
				selectnav(\''.$menuid.'\', {
					label: \''.t('--- Table of content ---').'\',//first select field
					nested: true,
					indent: \'-\'
			 });
		});
		})(jQuery);';
		drupal_add_js($selecnav, 'inline');
		$vp = array(
          '#type' => 'html_tag',
          '#tag' => 'meta',
          '#attributes' => array(
            'name' =>  'viewport',
            'content' =>  'width=100%, initial-scale=1, maximum-scale=1, minimum-scale=1, user-scalable=no'
          )
        );
        drupal_add_html_head($vp, 'viewport');
	}

    $vars['theme_setting_css'] = $css;
	// Typekit
	if (theme_get_setting('typekit_id','md_magnum')) {
		drupal_add_js('http://use.typekit.net/'.theme_get_setting('typekit_id','md_magnum').'.js', 'external');
		drupal_add_js('try{Typekit.load();}catch(e){}', 'inline');
	}

	/* Text/typography
	---------------------------------------------------------------------------------------- */
	$typography = '';
	// common text
	if (theme_get_setting('text_font','md_magnum') || theme_get_setting('ts_font_color','md_magnum')) {
    $typography = "body {";
    $typography .= md_magnum_font_to_css(theme_get_setting('text_font','md_magnum'));
		if (theme_get_setting('ts_font_color','md_magnum')) {
      $typography .= 'color: #' . theme_get_setting('ts_font_color') . ';';
		}
    $typography   .= "}\n";
	}
    /////
  $text_font_arr = explode("|", theme_get_setting('text_font','md_magnum'));
  if (count($text_font_arr) == 5 && $text_font_arr[0] != '0') {
    $typography   .= '#forum, ul.quicktabs-tabs, #nav ul.sf-menu li li,.ui-widget {font-family: '.$text_font_arr[4].';}';
  }
    /////
	// Text selection
	if (theme_get_setting('tss_bgcolor','md_magnum') || theme_get_setting('tss_tcolor','md_magnum')) {
    $tss_bgcolor = '';
    $tss_tcolor = '';
		if (theme_get_setting('tss_bgcolor','md_magnum')) {
		  $tss_bgcolor   = 'background: #'.theme_get_setting('tss_bgcolor','md_magnum').';';
		}
		if (theme_get_setting('tss_tcolor','md_magnum')) {
		  $tss_tcolor   = 'color: #'.theme_get_setting('tss_tcolor','md_magnum').';';
		}
    $typography   .= "::-moz-selection {". $tss_bgcolor . $tss_tcolor . "text-shadow: none;}\n";
    $typography   .= "::selection {" . $tss_bgcolor . $tss_tcolor. "text-shadow: none;}\n";
	}
	// link regular
	if (theme_get_setting('l_regular_color','md_magnum') || theme_get_setting('l_regular_st','md_magnum') || theme_get_setting('l_regular__hl','md_magnum') || theme_get_setting('l_regular_ts','md_magnum')) {
    $typography   .= "a:link, #node-title a {";
		if (theme_get_setting('l_regular_color','md_magnum')) {
      $typography   .= 'color: #'.theme_get_setting('l_regular_color','md_magnum').';';
		}
		if (theme_get_setting('l_regular__hl','md_magnum')) {
		  $typography   .= 'background-color: #'.theme_get_setting('l_regular__hlc','md_magnum').';';
		}
        if(theme_get_setting('l_regular_st','md_magnum') == 1) {
            $typography .= 'text-decoration: line-through';
        }
		$l_text_style = theme_get_setting('l_regular_ts','md_magnum');
		if ($l_text_style['bold']) {
		  $typography   .= 'font-weight: '.$l_text_style['bold'].';';
		}
		if ($l_text_style['italic']) {
		  $typography   .= 'font-style: '.$l_text_style['italic'].';';
		}
		if ($l_text_style['underline']) {
		  $typography   .= 'text-decoration: '.$l_text_style['underline'].';';
		}
		$typography   .= "}\n";
	}
	// link rollover
	if (theme_get_setting('l_rollover_color','md_magnum') || theme_get_setting('l_rollover_st','md_magnum') || theme_get_setting('l_rollover__hl','md_magnum') || theme_get_setting('l_rollover_ts','md_magnum')) {
		$typography   .= "a:hover, #node-title a:hover {";
		if (theme_get_setting('l_rollover_color')) {
		  $typography   .= 'color: #'.theme_get_setting('l_rollover_color','md_magnum').';';
		}
		if (theme_get_setting('l_rollover__hl')) {
		  $typography   .= 'background-color: #'.theme_get_setting('l_rollover__hlc','md_magnum').';';
		}
        if(theme_get_setting('l_rollover_st','md_magnum') == 1) {
            $typography .= 'text-decoration: line-through';
        }
		$l_text_style = theme_get_setting('l_rollover_ts','md_magnum');
		if ($l_text_style['bold']) {
		  $typography   .= 'font-weight: '.$l_text_style['bold'].';';
		}
		if ($l_text_style['italic']) {
		  $typography   .= 'font-style: '.$l_text_style['italic'].';';
		}
		if ($l_text_style['underline']) {
		  $typography   .= 'text-decoration: '.$l_text_style['underline'].';';
		}
		$typography   .= "}\n";
	}

	// link visited
	if (theme_get_setting('l_visited_color','md_magnum') || theme_get_setting('l_visited_st','md_magnum') || theme_get_setting('l_visited__hl','md_magnum') || theme_get_setting('l_visited_ts','md_magnum')) {
		$typography   .= "a:visited, #node-title a:visited {";
		if (theme_get_setting('l_visited_color')) {
		  $typography   .= 'color: #'.theme_get_setting('l_visited_color','md_magnum').';';
		}
		if (theme_get_setting('l_visited__hl')) {
		  $typography   .= 'background-color: #'.theme_get_setting('l_visited__hlc','md_magnum').';';
		}
        if(theme_get_setting('l_visited_st','md_magnum') == 1) {
            $typography .= 'text-decoration: line-through';
        }
		$l_text_style = theme_get_setting('l_visited_ts','md_magnum');
		if ($l_text_style['bold']) {
		  $typography   .= 'font-weight: '.$l_text_style['bold'].';';
		}
		if ($l_text_style['italic']) {
		  $typography   .= 'font-style: '.$l_text_style['italic'].';';
		}
		if ($l_text_style['underline']) {
		  $typography   .= 'text-decoration: '.$l_text_style['underline'].';';
		}
		$typography   .= "}\n";
	}

	// link on
	if (theme_get_setting('l_on_color','md_magnum') || theme_get_setting('l_on_st','md_magnum') || theme_get_setting('l_on_hl','md_magnum') || theme_get_setting('l_on_ts','md_magnum')) {
		$typography   .= "a:focus, a:active, #node-title a:focus, #node-title a:active {";
		if (theme_get_setting('l_on_color')) {
		  $typography   .= 'color: #'.theme_get_setting('l_on_color','md_magnum').';';
		}
		if (theme_get_setting('l_on_hl')) {
		  $typography   .= 'background-color: #'.theme_get_setting('l_on_hlc','md_magnum').';';
		}
        if(theme_get_setting('l_on_st','md_magnum') == 1) {
            $typography .= 'text-decoration: line-through';
        }
		$l_text_style = theme_get_setting('l_on_ts','md_magnum');
		if ($l_text_style['bold']) {
		  $typography   .= 'font-weight: '.$l_text_style['bold'].';';
		}
		if ($l_text_style['italic']) {
		  $typography   .= 'font-style: '.$l_text_style['italic'].';';
		}
		if ($l_text_style['underline']) {
		  $typography   .= 'text-decoration: '.$l_text_style['underline'].';';
		}
		$typography   .= "}\n";
	}
	// Main menu
	if (theme_get_setting('typo_menu_style','md_magnum') || theme_get_setting('typo_menu_color','md_magnum')) {
		$typography   .= "#menu li{";
		if (theme_get_setting('text_font','md_magnum')) {
		  $typography   .= md_magnum_font_to_css(theme_get_setting('typo_menu_style','md_magnum'));
		}

		if (theme_get_setting('typo_menu_color','md_magnum')) {
		  $typography   .= 'color: #'.theme_get_setting('typo_menu_color','md_magnum').';';
		}
		$typography   .= "}\n";

		if (theme_get_setting('typo_menu_color','md_magnum')) {
		  $typography   .= '#menu li a, #nav ul.sf-menu li a {color: #'.theme_get_setting('typo_menu_color','md_magnum').';}';
		}
		if (theme_get_setting('typo_menu_hover_color','md_magnum')) {
		  $typography   .= '#menu li > a:hover,#menu li.sfHover > a, #main li:hover a {color: #'.theme_get_setting('typo_menu_hover_color','md_magnum').';}'."\n";
		}
		if (theme_get_setting('typo_menu_active_color','md_magnum')) {
		  $typography   .= '#menu li > a:hover, #menu li.sfHover > a, #menu li a.active, #menu li.active a {color: #'.theme_get_setting('typo_menu_active_color','md_magnum').';}'."\n";
		}
	}
    /*-------------------------------------- Heading --------------------------------*/
    if(theme_get_setting('typo_heading_style_enable','md_magnum') == 1){
        for($i=1;$i<=6;$i++){
            $typography .= 'h'.$i.' {';
            if(theme_get_setting('typo_heading_h'.$i.'_style') || theme_get_setting('typo_heading_h'.$i.'_color','md_magnum')){
                if(theme_get_setting('typo_heading_h'.$i.'_style')){
                    $typography .= md_magnum_font_to_css(theme_get_setting('typo_heading_h'.$i.'_style'));
                }
                if(theme_get_setting('typo_heading_h'.$i.'_color','md_magnum')){
                    $typography .= ' color: #'.theme_get_setting('typo_heading_h'.$i.'_color').';';
                }
            }
            $typography .= "}\n";
        }
    }
	/*------------------------------------ Node title ---------------------------------*/
	if (theme_get_setting('typo_nodetitle_style','md_magnum') || theme_get_setting('nodetitle_color','md_magnum')) {
		$typography   .= "#node-title {";
		if (theme_get_setting('typo_nodetitle_style')) {
		  $typography   .= md_magnum_font_to_css(theme_get_setting('typo_nodetitle_style'));
		}

		if (theme_get_setting('nodetitle_color','md_magnum')) {
		  $typography   .= 'color: #'.theme_get_setting('nodetitle_color','md_magnum').';';
		}
		$typography   .= "}\n";

		if (theme_get_setting('nodetitle_color')) {
		  $typography   .= '#node-title a {color: #'.theme_get_setting('nodetitle_color','md_magnum').';}'."\n";
		}

		if (theme_get_setting('nodetitle_hover_color')) {
		  $typography   .= '#node-title a:hover {color: #'.theme_get_setting('nodetitle_hover_color','md_magnum').';}'."\n";
		}
	}

	if (theme_get_setting('nodetitle_enable','md_magnum') == 1) {
		foreach (node_type_get_types() as $type => $name) {
			if (theme_get_setting('typo_n'.$type.'title_style') || theme_get_setting('n'.$type.'title_color','md_magnum')) {
				$typography   .= "#node-title span.node-$type-title {";
				if (theme_get_setting('typo_n'.$type.'title_style')) {
				  $typography   .= md_magnum_font_to_css(theme_get_setting('typo_n'.$type.'title_style','md_magnum'));
				}

				if (theme_get_setting('n'.$type.'title_color','md_magnum')) {
				  $typography   .= 'color: #'.theme_get_setting('n'.$type.'title_color','md_magnum').';';
				}
				$typography   .= "}\n";

				if (theme_get_setting('n'.$type.'title_color','md_magnum')) {
				  $typography   .= '#node-title span.node-'.$type.'-title a {color: #'.theme_get_setting('n'.$type.'title_color','md_magnum').';}'."\n";
				}

				if (theme_get_setting('n'.$type.'title_hover_color','md_magnum')) {
				  $typography   .= '#node-title span.node-'.$type.'-title a:hover {color: #'.theme_get_setting('n'.$type.'title_hover_color','md_magnum').';}'."\n";
				}
			}
		}
	}

    // View block title
    if (theme_get_setting('typo_view_title_style','md_magnum') || theme_get_setting('typo_view_title_color','md_magnum')) {
        $typography   .= ".flx-intro-2 h2 {";
        if (theme_get_setting('typo_view_title_style','md_magnum')) {
            $typography   .= md_magnum_font_to_css(theme_get_setting('typo_view_title_style','md_magnum'));
        }

        if (theme_get_setting('typo_view_title_color')) {
            $typography   .= 'color: #'.theme_get_setting('typo_view_title_color','md_magnum').' !important;';
        }
        $typography   .= "}\n";

    }

    if (theme_get_setting('typo_view_title_enable','md_magnum') == 1) {
        $views = views_get_all_views($reset = FALSE);
        foreach ($views as $view_name => $view) {
            if(($view->disabled) !== true){
                $view_title = $view->name;

                if (theme_get_setting('typo_view_'.$view_title.'_title_style') || theme_get_setting('typo_view_'.$view_title.'_title_color','md_magnum')) {
                    $typography   .= ".flx-intro-2 h2.view-".$view_title."-title {";
                    if (theme_get_setting('typo_view_'.$view_title.'_title_style')) {
                        $typography   .= md_magnum_font_to_css(theme_get_setting('typo_view_'.$view_title.'_title_style','md_magnum'));
                    }

                    if (theme_get_setting('typo_view_'.$view_title.'_title_color','md_magnum')) {
                        $typography   .= 'color: #'.theme_get_setting('typo_view_'.$view_title.'_title_color','md_magnum').' !important;';
                    }
                    $typography   .= "}\n";
                }
            }

        }
    }
    //View block description
    if (theme_get_setting('typo_view_description_style','md_magnum') || theme_get_setting('typo_view_description_color','md_magnum')) {
        $typography   .= ".flx-intro-2 h5.flx-intro-excerpt {";
        if (theme_get_setting('typo_view_description_style','md_magnum')) {
            $typography   .= md_magnum_font_to_css(theme_get_setting('typo_view_description_style','md_magnum'));
        }

        if (theme_get_setting('typo_view_description_color','md_magnum')) {
            $typography   .= 'color: #'.theme_get_setting('typo_view_description_color','md_magnum').' !important;';
        }
        $typography   .= "}\n";

    }

    if (theme_get_setting('typo_view_description_enable','md_magnum') == 1) {
        $views = views_get_all_views($reset = FALSE);
        foreach ($views as $view_name => $view) {
            if(($view->disabled) !== true){
                $view_title = $view->name;

                if (theme_get_setting('typo_view_'.$view_title.'_description_style','md_magnum') || theme_get_setting('typo_view_'.$view_title.'_description_color','md_magnum')) {
                    $typography   .= ".flx-intro-2 span.view-".$view_title."-description {";
                    if (theme_get_setting('typo_view_'.$view_title.'_description_style','md_magnum')) {
                        $typography   .= md_magnum_font_to_css(theme_get_setting('typo_view_'.$view_title.'_description_style','md_magnum'));
                    }

                    if (theme_get_setting('typo_view_'.$view_title.'_description_color','md_magnum')) {
                        $typography   .= 'color: #'.theme_get_setting('typo_view_'.$view_title.'_description_color','md_magnum').' !important;';
                    }
                    $typography   .= "}\n";
                }
            }

        }
    }
    if (theme_get_setting('typo_webformtitle_style','md_magnum') || theme_get_setting('typo_webformtitle_color','md_magnum')) {
        $typography   .= ".flx-map-form span.webform-title{";
        if (theme_get_setting('typo_webformtitle_style','md_magnum')) {
            $typography   .= md_magnum_font_to_css(theme_get_setting('typo_webformtitle_style','md_magnum'));
        }

        if (theme_get_setting('typo_webformtitle_color','md_magnum')) {
            $typography   .= 'color: #'.theme_get_setting('typo_webformtitle_color','md_magnum').' !important;';
        }
        $typography   .= "}\n";

    }
    if (theme_get_setting('typo_webformdescription_style','md_magnum') || theme_get_setting('typo_webformdescription_color','md_magnum')) {
        $typography   .= ".flx-map-form span.webform-description{";
        if (theme_get_setting('typo_webformdescription_style','md_magnum')) {
            $typography   .= md_magnum_font_to_css(theme_get_setting('typo_webformdescription_style','md_magnum'));
        }

        if (theme_get_setting('typo_webformdescription_color','md_magnum')) {
            $typography   .= 'color: #'.theme_get_setting('typo_webformdescription_color','md_magnum').' !important;';
        }
        $typography   .= "}\n";
    }

	$vars['typography'] = $typography;

	/* Get theme settings
	---------------------------------------------------------------------------------------- */
	$vars['footer_text']   = theme_get_setting('footer_text','md_magnum');
	$vars['header_code']   = theme_get_setting('header_code','md_magnum');
	$vars['footer_code']   = theme_get_setting('footer_code','md_magnum');
	if (theme_get_setting('custom_css','md_magnum')) {
		$vars['custom_css']  = theme_get_setting('custom_css','md_magnum');
	}
	drupal_add_css(path_to_theme() . '/css/ie7.css', array('group' => CSS_THEME, 'browsers' => array('IE' => 'lte IE 7', '!IE' => FALSE), 'preprocess' => FALSE));
}

function md_magnum_font_to_css($font) {
    $font_arr = explode("|", $font);
    $css = "";
    if(count($font_arr) == 6) {
        if ($font_arr[0] != '0') {
            $css = ''.$font_arr[5].';';
        }
    }
    return $css;
}

function md_magnum_expand_font_weight($fw) {
				switch($fw) {
					case 'n1':
						$fontExpand = "font-style: normal; font-weight: 100;";
				  	break;
					case 'i1':
						$fontExpand = "font-style: italic; font-weight: 100;";
						break;
					case 'n2':
						$fontExpand = "font-style: normal; font-weight: 200;";
				  	break;
					case 'i2':
						$fontExpand = "font-style: italic; font-weight: 200;";
						break;
					case 'n3':
						$fontExpand = "font-style: normal; font-weight: 300;";
				  	break;
					case 'i3':
						$fontExpand = "font-style: italic; font-weight: 300;";
						break;
					case 'n4':
						$fontExpand = "font-style: normal; font-weight: normal;";
				  	break;
					case 'i4':
						$fontExpand = "font-style: italic; font-weight: normal";
						break;
					case 'n5':
						$fontExpand = "font-style: normal; font-weight: 500;";
				  	break;
					case 'i5':
						$fontExpand = "font-style: italic; font-weight: 500;";
						break;
					case 'n6':
						$fontExpand = "font-style: normal; font-weight: 600;";
				  	break;
					case 'i6':
						$fontExpand = "font-style: italic; font-weight: 600;";
						break;
					case 'n7':
						$fontExpand = "font-style: normal; font-weight: bold;";
				  	break;
					case 'i7':
						$fontExpand = "font-style: italic; font-weight: bold;";
						break;
					case 'n8':
						$fontExpand = "font-style: normal; font-weight: 800;";
				  	break;
					case 'i8':
						$fontExpand = "font-style: italic; font-weight: 800;";
						break;
					case 'n9':
						$fontExpand = "font-style: normal; font-weight: 800;";
				  	break;
					case 'i9':
						$fontExpand = "font-style: italic; font-weight: 800;";
						break;
					default:
						$fontExpand = "";
				}

				return $fontExpand;
			}

/**
 * Override or insert vars into the page template for HTML output.
 */
function md_magnum_process_html(&$vars) {
  // Hook into color.module.
  if (module_exists('color')) {
    _color_html_alter($vars);
  }

	$classes = explode(' ', $vars['classes']);
  if ($node = menu_get_object()) {
    $node_type_class = drupal_html_class('node-type-' . $node->type);
    if (in_array($node_type_class, $classes)) {
      theme_get_setting('extra_page_classes','md_magnum') == 0 ? '' : $classes = str_replace($node_type_class, '', $classes);
      $classes = str_replace('node-type-', 'page-type-', $classes);
    }
  }
  $vars['classes'] = trim(implode(' ', $classes));
}



/**
 * Override or insert vars into the page template.
 */
function md_magnum_process_page(&$vars) {
  // Hook into color.module.
  if (module_exists('color')) {
    _color_page_alter($vars);
  }

	$status = drupal_get_http_header("status");
  if($status == "404 Not Found") {
    $vars['theme_hook_suggestions'][] = 'page__404';
  }

	$vars['social_links'] = 0;

  // Always print the site name and slogan, but if they are toggled off, we'll
  // just hide them visually.
  $vars['hide_site_name']   = theme_get_setting('toggle_name','md_magnum') ? FALSE : TRUE;
  $vars['hide_site_slogan'] = theme_get_setting('toggle_slogan','md_magnum') ? FALSE : TRUE;
  if ($vars['hide_site_name']) {
    // If toggle_name is FALSE, the site_name will be empty, so we rebuild it.
    $vars['site_name'] = filter_xss_admin(variable_get('site_name', 'Drupal'));
  }
  if ($vars['hide_site_slogan']) {
    // If toggle_site_slogan is FALSE, the site_slogan will be empty, so we rebuild it.
    $vars['site_slogan'] = filter_xss_admin(variable_get('site_slogan', ''));
  }
  // Since the title and the shortcut link are both block level elements,
  // positioning them next to each other is much simpler with a wrapper div.
  if (!empty($vars['title_suffix']['add_or_remove_shortcut']) && $vars['title']) {
    // Add a wrapper div using the title_prefix and title_suffix render elements.
    $vars['title_prefix']['shortcut_wrapper'] = array(
      '#markup' => '<div class="shortcut-wrapper clearfix">',
      '#weight' => 100,
    );
    $vars['title_suffix']['shortcut_wrapper'] = array(
      '#markup' => '</div>',
      '#weight' => -99,
    );
    // Make sure the shortcut link is the first item in title_suffix.
    $vars['title_suffix']['add_or_remove_shortcut']['#weight'] = -100;
  }

}

/**
 * Implements hook_preprocess_page().
 */
function md_magnum_preprocess_page(&$vars, $hook) {
    if(isset($vars['node'])) {
        $vars['page_title'] = $vars['node']->type;
    }
    if(theme_get_setting('footer_text','md_magnum')){
        $vars['footer_text'] = theme_get_setting('footer_text','md_magnum');
    }
    if(theme_get_setting('header_video_image_fallback','md_magnum')){
        $header_vd_image_fallback = theme_get_setting('header_video_image_fallback','md_magnum');

        $vars['header_vd_image_fallback'] = md_magnum_theme_setting_check_path($header_vd_image_fallback);
    }

    if(theme_get_setting('nf_video_image_fallback','md_magnum')){
        $nf_vd_image_fallback = theme_get_setting('nf_video_image_fallback','md_magnum');

        $vars['nf_vd_image_fallback'] = md_magnum_theme_setting_check_path($nf_vd_image_fallback);
    }

    /* ----------------------------  Preloader ----------------------------------------------*/
   $loader_js = "jQuery(window).load(function() { // makes sure the whole site is loaded
            jQuery('#status').delay(350).fadeOut('slow'); // will first fade out the loading animation
            jQuery('#pre-load-logo').delay(350).fadeOut('slow'); // second fade out the loading animation
            jQuery('#preloader').delay(350).fadeOut('slow'); // will fade out the white DIV that covers the website.
            jQuery('body').delay(350).css({'overflow-y':'visible'});
    })";

    drupal_add_js($loader_js,'inline');
    $preloader = '';
    $preloader .= '
        <!-- Preloader -->
            <div id="preloader">
              <div id="pre-load-logo"></div>';
        $preloader .= '<div id="status">';
        if(theme_get_setting('preloader_type','md_magnum')) {
            $preloader .= '<div id="pre'.theme_get_setting('preloader_type','md_magnum').'" class="slitem"></div>';
        }
        $preloader .= '</div>';
    $css_inline = '';
    if(theme_get_setting('preloader_bg_type','md_magnum') == 'custom') {
        $css_inline .= '#preloader {background-color: #'.theme_get_setting('preloader_bg_color','md_magnum').';}'."\n";
    } else {
        $skin = theme_get_setting('skins','md_magnum');
        $color = get_skin_color($skin);
        $css_inline .= '#preloader {background-color: '.$color.';}';
    }
    if(theme_get_setting('preloader_enable_logo','md_magnum') == '1') {
        if(theme_get_setting('preloader_logo_path','md_magnum')) {
            $preloader_logo_path = md_magnum_theme_setting_check_path(theme_get_setting('preloader_logo_path','md_magnum'));
            $css_inline .= '#pre-load-logo { background: url("'.$preloader_logo_path.'") no-repeat center;}'."\n";
        }
    }
    $preloader .= '</div>';

    $vars['preloader'] = $preloader;

    drupal_add_css($css_inline,'inline');
    $themepath = drupal_get_path('theme', 'md_magnum');
}
/**
 * Implements hook_preprocess_maintenance_page().
 */
function md_magnum_preprocess_maintenance_page(&$vars) {
    $theme_path = drupal_get_path('theme','md_magnum');
    if(module_exists('fontello')) {
        drupal_add_css(drupal_get_path('module','fontello').'/css/fontello.fix.css');
        drupal_add_css('public://icon/fontello/fontello/css/fontello.css');
        drupal_add_css('public://icon/fontello/fontello/css/animation.css');
    }
   
    /********************************** Skin ********************************/
    if (theme_get_setting('skins') != '0') {
        drupal_add_css($theme_path . '/css/colors/'.theme_get_setting('skins').'.css', array('group' => CSS_THEME));
    }
    if (!$vars['db_is_active']) {
        unset($vars['site_name']);
    }
    // Always print the site name and slogan, but if they are toggled off, we'll
    // just hide them visually.
    $vars['hide_site_name']   = theme_get_setting('toggle_name') ? FALSE : TRUE;
    $vars['hide_site_slogan'] = theme_get_setting('toggle_slogan') ? FALSE : TRUE;
    if ($vars['hide_site_name']) {
        // If toggle_name is FALSE, the site_name will be empty, so we rebuild it.
        $vars['site_name'] = filter_xss_admin(variable_get('site_name', 'Drupal'));
    }
    if ($vars['hide_site_slogan']) {
        // If toggle_site_slogan is FALSE, the site_slogan will be empty, so we rebuild it.
        $vars['site_slogan'] = filter_xss_admin(variable_get('site_slogan', ''));
    }
}

function md_magnum_check_und($param) {
	if (isset($param['und'])) {
		return $param['und'][0];
	} else {
		return $param[0];
	}
}
function base_url(){
    global $base_url;
    return $base_url;
}
function theme_path() {
    $theme_path = drupal_get_path('theme','md_magnum');

    return $theme_path;
}
function get_skin_color ($skin_name) {
    $color = '';
    switch ($skin_name) {
        case 'default':
            $color = '#bba454';
            break;
        case 'yellow':
            $color = '#e5ae09';
            break;
        case 'green':
            $color = '#9cc045';
            break;
        case 'ruby':
            $color = '#cc144d';
            break;
        case 'teal':
            $color = '#14b4cc';
            break;
        case 'blue':
            $color = '#6ac0d5';
            break;
        case 'orange':
            $color = '#ee5e07';
            break;
        case 'purple':
            $color = '#7e599d';
            break;
    }
    return $color;
}