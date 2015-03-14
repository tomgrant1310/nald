
<?php if(isset($preloader)):?>
    <?php print $preloader;?>
<?php endif;?>

<?php if($page['header']):?>
    <?php print render($page['header']);?>
<?php endif;?>

<?php if($page['navigation']):?>
    <?php print render($page['navigation']);?>
<?php endif;?>

<?php if($page['introduction']):?>
    <?php print render($page['introduction']);?>
<?php endif;?>
<!-- Featured work -->
<section id="work" class="featured-work">
<?php if($page['work']):?>
    <?php print render($page['work']);?>
<?php endif;?>
</section>

<?php if($page['parallax_1']):?>
    <section id="parallax-1" class="parallax">
        <?php print render($page['parallax_1']);?>
    </section>
<?php endif;?>

<?php if($page['about_me']):?>
<!-- About me -->
<section id="about" class="about">
    <?php print render($page['about_me']);?>
</section>
<?php endif;?>

<?php if($page['about_us']):?>
  <!-- About us -->
  <section id="about" class="about-us">
    <?php print render($page['about_us']);?>
  </section>
<?php endif;?>

<?php if($page['parallax_2']):?>
    <section id="parallax-2" class="parallax">
        <?php print render($page['parallax_2']);?>
    </section>
<?php endif;?>


<?php if($page['single_services']):?>
<!-- Services -->
<section id="services" class="services">
    <?php print render($page['single_services']);?>
</section>
<?php endif;?>

<?php if($page['business_services']):?>
  <!-- Services -->
  <section id="services" class="simple-services">
    <?php print render($page['business_services']);?>
  </section>
<?php endif;?>

<?php if($page['parallax_3']):?>
    <section id="parallax-3" class="parallax">
        <?php print render($page['parallax_3']);?>
    </section>
<?php endif;?>

<!-- Contact -->
<section id="contact" class="contact">
<?php if($page['contact']):?>
        <?php print render($page['contact']);?>
<?php endif;?>
</section>
<!-- The footer -->

<?php if($page['footer']):?>
    <?php print render($page['footer']);?>
<?php endif;?>
