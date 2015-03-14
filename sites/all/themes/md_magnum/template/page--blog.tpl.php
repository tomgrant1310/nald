<?php if($page['navigation']):?>
    <?php print render($page['navigation']);?>
<?php endif;?>
<section id="main-content">
    <!-- Blog header -->
    <section id="top" class="blog-header">
        <div class="row">
            <div class="twelve columns">

                <!-- The title -->
                <div class="title">
                    <h1>The Blog</h1>
                    <hr>
                </div>

            </div>
        </div>
    </section>

    <!-- Blog index -->
    <section class="blog">
        <div class="row">

        <?php if($page['content']):?>
            <?php print render($page['content']);?>
        <?php endif;?>
        <?php if($page['sidebar']):?>
            <div class="three columns">
            <?php print render($page['sidebar']);?>
            </div>
        <?php endif;?>

        </div>
    </section>
    </section>
<?php
if(theme_get_setting('footer_background') == 'global') {
    if(theme_get_setting('header_background_type') == 'video') {
        if(theme_get_setting('header_video_image_fallback','md_magnum')){
            $header_vd_image_fallback = theme_get_setting('header_video_image_fallback','md_magnum');

            $header_vd_image_scheme = file_uri_scheme($header_vd_image_fallback);
            if ($header_vd_image_scheme == 'public') {

                $path = file_create_url($header_vd_image_fallback);
            } else if (($header_vd_image_scheme == 'http') || ($header_vd_image_scheme == 'https')) {
                $path = $header_vd_image_fallback;
            } else {
                $path = file_create_url(file_build_uri($header_vd_image_fallback));
            }
            $hd_vd_fallback_path = $path;
        } else {
            $hd_vd_fallback_path = base_url().'/'.drupal_get_path('themes','md_magnum').'/images/bg2.jpg';
        }
    }

    if(theme_get_setting('header_background_type') == 'custom') {
        if(theme_get_setting('header_slide_image_fallback','md_magnum')){
            $header_slider_image_fallback = theme_get_setting('header_slide_image_fallback','md_magnum');

            $header_slide_image_scheme = file_uri_scheme($header_slider_image_fallback);
            if ($header_slide_image_scheme == 'public') {

                $path = file_create_url($header_slider_image_fallback);
            } else if (($header_slide_image_scheme == 'http') || ($header_slide_image_scheme == 'https')) {
                $path = $header_slider_image_fallback;
            } else {
                $path = file_create_url(file_build_uri($header_slider_image_fallback));
            }

            $hd_sl_fallback_path = $path;
        } else {
            $hd_sl_fallback_path = base_url().'/'.drupal_get_path('themes','md_magnum').'/images/bg2.jpg';
        }
    }


}
?>
<?php if($page['footer']):?>
    <?php
    if(theme_get_setting('footer_background') == 'global') {
        if(theme_get_setting('header_background_type') == 'custom') { ?>
            <div style="background-image: url('<?php if(isset($hd_sl_fallback_path)) {print $hd_sl_fallback_path;} ?>');" class="page-fallback-image"></div>
        <?php }?>
        <?php
        if(theme_get_setting('header_background_type') == 'video') {?>
            <div style="background-image: url('<?php if(isset($hd_vd_fallback_path)) {print $hd_vd_fallback_path;}?>');" class="page-fallback-image"></div>
        <?php }
    } ?>
    <?php print render($page['footer']);?>
<?php endif;?>
