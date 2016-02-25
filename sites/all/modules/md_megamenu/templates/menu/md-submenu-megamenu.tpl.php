<?php
/**
 * File: md-submenu-megamenu.tpl.php
 * Author: MegaDrupal
 * Website: http://megadrupal.com/
 */
?>
<li class="awemenu-item">
	<div class="awemenu-megamenu-wrapper">
		<?php foreach ($rows as $row):?>
		<div class="row"<?php if ($row['style']) print ' ' . $row['style'];?>>
			<?php foreach ($row['columns'] as $column):?>
			<div class="<?php print implode(' ', $column['classes']);?>"<?php if ($column['style']) print ' ' . $column['style'];?>>
			<?php print drupal_render($column['content']);?>
			</div>
			<?php endforeach;?>
		</div>
		<?php endforeach;?>
	</div>
</li>