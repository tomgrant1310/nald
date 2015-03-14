<?php print render($title_prefix); ?>
<?php print render($title_suffix); ?>
<!-- 404 -->
<div id="nf-slider" class="backslider">
    <?php if(theme_get_setting('nf_slide','md_magnum')):?>
        <ul class="bs-slides">
            <?php $css =''; $nf_image = theme_get_setting('nf_image_slide','md_magnum');
            if(count($nf_image) > 1) {
                foreach ($nf_image as $key => $value) {
                    if($nf_image[$key]['image'] != null){
                        $nf_image_path = file_create_url(file_build_uri($nf_image[$key]['image']));?>
                        <li><img src="<?php print $nf_image_path;?> " alt="Pic"></li>
                    <?php }
                }
            } else {
                $css .= '#nf-slider {background-image: url("'.md_magnum_theme_setting_check_path($nf_image['nf_slide_hidden_1']['nf_image_path']).'");}';
            }?>
        </ul>
    <?php endif;?>
<div class="fourofour">
    <div class="fourofour-content text-white">
        <!-- Text -->
        <h1 class="text-white">404</h1>
        <h4 class="big serif italic margin-bottom"><?php print theme_get_setting('nf_text','md_magnum');?></h4>
        <!-- Back to home button -->
        <a href="<?php print base_url();?>">
            <?php $nf_icon = theme_get_setting('nf_button_icon','md_magnum');?>
            <i class="<?php if(isset($nf_icon['bundle'])):print $nf_icon['bundle'];endif;?> <?php  if(isset($nf_icon['icon'])): print $nf_icon['icon'];endif;?>"></i>
            <b><?php print theme_get_setting('nf_button_text','md_magnum');?></b>
            <em><?php print theme_get_setting('nf_button_sub_text','md_magnum');?></em>
        </a>
    </div>
</div>
<?php if(theme_get_setting('nf_background','md_magnum') == 'video'):?>
<!-- Background with youtube video -->
<div class="video-container">
    <a id="nf-video" class="fullscreen-video" data-property="{videoURL:'<?php print theme_get_setting('nf_video_link','md_magnum');?>'}"></a>
</div>


<!-- Video controls -->
<div class="video-controls" id="nf-video-controls">
    <button class="small-play-btn" onclick="jQuery('#nf-video').playYTP()"><i class="fontello icon icon-play"></i></button>
    <button class="small-pause-btn" onclick="jQuery('#nf-video').pauseYTP()"><i class="fontello icon icon-pause"></i></button>
    <button onclick="jQuery('#nf-video').toggleVolume()"><i class="fontello icon icon-volume-up"></i></button>
</div>


<!-- Background image to display when the video doesn't play anymore -->
<div style="background-image: url('<?php if(isset($nf_vd_image_fallback)) {print $nf_vd_image_fallback;};?>');" class="video-fullscreen-img"></div>
<?php endif;?>
<?php if(theme_get_setting('nf_background','md_magnum') == 'custom'):?>
</div>
<?php endif;?>