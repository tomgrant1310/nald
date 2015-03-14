<?php
global $base_url;
if(isset($row->field_field_blog_multimedia)) {
    $multimedia = $row->field_field_blog_multimedia;
    $count = count($multimedia);
    $slide_content = '';
    $type = array();
    if($count > 1) {
        foreach($multimedia as $key => $value){
            $bundle_type = $value['rendered']['#bundle'];
            $type[] = $bundle_type;
            if($bundle_type == 'image'){
                $image = file_create_url($value['rendered']['file']['#item']['uri']);
                $slide_content .= '<li><img src="'.$image.'"/></li>';
            }
        }
        foreach ($type as $key => $value) {
            if($value != 'image') {
                $slide_content = '';
            }
        }

    }
}
?>
<div class="post post-single">
    <div class="inner-spacer-right-lrg">
        <div class="post-title">
            <h3><a href="<?php print $base_url.'/node/'.$row->nid.'';?>"><?php print $row->node_title;?></a></h3>
            <div class="post-meta">
                By <?php print $fields['name']->content;?> on <?php print $fields['created']->content;;?> in <?php print $fields['field_blog_category']->content;?>
            </div>
        </div>
        <div class="post-media">
            <?php if(isset($slide_content) && $slide_content != null){?>
                <div class="flexslider" id="feature-post-slider">
                    <ul class="slides bxslider">
                        <?php
                        print $slide_content;
                        ?>
                    </ul>
                </div><!--bp-flex-->
            <?php } else {?>
                <?php print $fields['field_blog_multimedia']->content;?>
            <?php }?>
        </div>
    </div>

    <div class="post-body">
        <?php print $fields['body']->content;?>

    </div>

    <div class="tags">
        <?php foreach($row->field_field_blog_tag as $key => $value) {
            print '<a href="'.$base_url.'/'.$value['rendered']['#href'].'">'.$value['rendered']['#title'].'</a>';
        } ?>
    </div>
</div>
