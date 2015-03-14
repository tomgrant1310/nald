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
        <!-- The posts -->
        <div class="nine columns">
            <?php if($page['content']):?>
            <?php print render($page['content']);?>
            <?php endif;?>
        </div>

        <?php if($page['sidebar']):?>
            <!-- Sidebar -->
            <div class="three columns">
                <div class="sidebar">
                    <?php print render($page['sidebar']);?>
                </div>
            </div>
        <?php endif;?>

    </div>
</section>


<!-- The footer -->
<section class="footer-two">
    <div class="row">
        <div class="twelve columns">


            <!-- Back to top button -->
            <p><a href="#home" class="smoothscroll"><i class="icon icon-up-open"></i></a></p>


            <!-- Social icons -->
            <?php $twitter_acc = theme_get_setting('twitter_account');
            $skype_acc = theme_get_setting('skype_account');
            $facebook_acc = theme_get_setting('facebook_account');
            $youtube_channel = theme_get_setting('youtube_channel');
            $gplus = theme_get_setting('google+_account');
            $linkedin = theme_get_setting('dribbble_account');
            $pinterest = theme_get_setting('pinterest_account');
            $dribbble = theme_get_setting('linkedin_account'); ?>
            <?php if($twitter_acc != null || $skype_acc != null || $facebook_acc != null || $youtube_channel != null || $gplus != null || $linkedin != null || $pinterest != null || $dribbble != null ):?>
                <p class="socials">
                    <?php if($twitter_acc != null):?><a href="<?php print $twitter_acc;?>" target="_blank"><i class="icon-twitter icon outline light"></i></a><?php endif;?>
                    <?php if($facebook_acc != null):?><a href="<?php print $facebook_acc;?>" target="_blank"><i class="icon-facebook icon outline light"></i></a><?php endif;?>
                    <?php if($skype_acc != null):?><a href="<?php print $skype_acc;?>" target="_blank"><i class="icon-skype icon outline light"></i></a><?php endif;?>
                    <?php if($youtube_channel != null):?><a href="<?php print $youtube_channel;?>" target="_blank"><i class="icon-youtube icon outline light"></i></a><?php endif;?>
                    <?php if($gplus != null):?><a href="<?php print $gplus;?>" target="_blank"><i class="icon-gplus icon outline light"></i></a><?php endif;?>
                    <?php if($dribbble != null):?><a href="<?php print $dribbble;?>" target="_blank"><i class="icon-dribbble icon outline light"></i></a><?php endif;?>
                    <?php if($pinterest != null):?><a href="<?php print $pinterest;?>" target="_blank"><i class="icon-pinterest-circled icon outline light"></i></a></li><?php endif;?>
                    <?php if($linkedin != null):?><a href="<?php print $linkedin;?>" target="_blank"><i class="icon-linkedin icon outline light"></i></a><?php endif;?>
                </p>
            <?php endif;?>

            <!-- Credits -->
            <p class="text-light"><?php print theme_get_setting('footer_text','md_magnum');?></p>


        </div>
    </div>
</section>