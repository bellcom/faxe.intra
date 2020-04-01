<?php
hide($content['comments']);
hide($content['links_top']);
hide($content['links_bottom']);
hide($content['links']);
if (isset($content['add_to_cart_form'])) {
  hide($content['add_to_cart_form']);
}

if (isset($content['field_os2intra_images'])) {
  hide($content['field_os2intra_images']);
}
?>
<!-- node.tpl.php -->
<!-- Begin - full node -->
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> os2-node-full"<?php print $attributes; ?>>

  <?php if (isset($content['field_os2intra_images'])): ?>
    <!-- Begin - image -->
    <div class="os2-node-full-image">
      <?php print render($content['field_os2intra_images']); ?>
    </div>
    <!-- End - image -->
  <?php endif; ?>
  <?php if (!empty($content['links_top'])): ?>
    <!-- Begin - controlpanel -->
    <div class="os2-node-full-controlpanel">

      <!-- Begin - links -->
      <div class="os2-links os2-links-top">
        <?php print render($content['links_top']); ?>
      </div>
      <!-- End - links -->

    </div>
    <!-- End - controlpanel -->
  <?php endif ?>
  <div class="os2-node-full-heading">
    <?php print render($title_prefix); ?>
    <h2<?php print $title_attributes; ?> class="os2-node-full-heading-title"><?php print $title; ?></h2>
    <?php print render($title_suffix); ?>
  </div>
  <?php if (isset($content)): ?>
    <!-- Begin - body -->
    <div class="os2-node-full-body">
      <?php print render($content); ?>
      <div class="field field-label-inline clearfix">
         <div class="field-label"> <?php print t('Varenummer') ?>:&nbsp;</div>
         <div class="field-items"><?php print $node->nid ?> </div>
      </div>
    </div>
    <!-- End - body -->
  <?php endif; ?>
  <?php if (isset($content['add_to_cart_form'])): ?>
    <div class="add-to-cart-form">
      <?php  print render($content['add_to_cart_form']); ?>
    </div>
  <?php endif; ?>

</div>
<!-- End - full node -->
