
<?php
global $base_url;
if(isset($content['field_blog_multimedia'])) {
    $multimedia = $content['field_blog_multimedia']['#items'];
    $count = count($multimedia);
    $slide_content = '';
    foreach($multimedia as $key => $value){
        $file_type = $value['file']->type;
        $image = file_create_url($value['file']->uri);
        $slide_content .= '<li><img src="'.$image.'"/></li>';
    }
}
?>
<?php ?>
    <!-- Post with an image -->
    <div class="post post-single">
        <div class="inner-spacer-right-lrg">
            <div class="post-title">
                <h3><a href="<?php print $base_url.'/node/'.$node->nid.'';?>"><?php print $node->title;?></a></h3>
                <div class="post-meta">
                    By <?php print $node->name;?> on <?php print date('F d,Y',$node->created);?> in <a href="<?php print $content['field_blog_category'][0]['#href'];?>"><?php print $content['field_blog_category'][0]['#title'];?></a>
                </div>
            </div>
            <div class="post-media">
                <!-- 16:9 format image here -->
                <?php if(isset($count) && $count >1 && isset($file_type) && $file_type == 'image'){?>
                    <div class="flexslider" id="bp-flex">
                        <ul class="bxslider featured-post-slider">
                            <?php
                            print $slide_content;
                            ?>
                        </ul>
                    </div><!--bp-flex-->
                <?php } else {?>
                    <?php print render($content['field_blog_multimedia']);?>
                <?php }?>
            </div>
        </div>

        <div class="post-body">
            <?php print render($content['body']);?>
        </div>

        <div class="tags">
            <?php foreach($content['field_blog_tag']['#items'] as $key => $value) {
                print '<a href="'.$base_url.'/taxonomy/term/'.$value['tid'].'">'.$value['taxonomy_term']->name.'</a>';
            } ?>
        </div>
    </div>




    <!-- Comment section cleaned up -->
    <div id="comments">
        <div class="commentsWrap">


            <?php if(isset($content['comments']['comments'])):?>
                <?php print render($content['comments']); ?>
            <?php endif;?>

        </div><!--end comments wrap-->
    </div><!--end comments-->

