<?php
hide($content['comments']);
if (isset($content['add_to_cart_form'])) {
 // hide($content['add_to_cart_form']);
}

if (isset($content['field_os2intra_images'])) {
  hide($content['field_os2intra_images']);
}

?>
<?php if ($view_mode == 'teaser'): ?>
  <!-- node--teaser.tpl.php -->
  <!-- Begin - teaser -->
  <article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> os2-node-teaser os2-box os2-box-small-spacing"<?php print $attributes; ?>>
    <div class="row">

        <?php if (isset($content['field_os2intra_images'])): ?>
          <div class="col-sm-3">

            <!-- Begin - images -->
            <div class="os2-node-teaser-image">
              <?php print render($content['field_os2intra_images']); ?>
            </div>
            <!-- End - images -->

          </div>
        <?php endif; ?>

        <div class="col-sm-9">

               <!-- End - entity info -->
          <?php endif ?>

          <!-- Begin - heading -->
          <div class="os2-node-teaser-heading">
            <h3 class="os2-node-teaser-heading-title"><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h3>
          </div>
          <!-- End - heading -->

          <!-- Begin - body -->
          <div class="os2-node-teaser-body">

            <?php //if (isset($content['field_furniture_description'])): ?>
              <!-- Begin - body -->
              <div class="os2-node-teaser-body-content">
                <?php print render($content['field_furniture_description']); ?>
                <?php print render($content['field_furniture_size']); ?>
                <div class="field field-label-inline clearfix">
                  <div class="field-label"> <?php print t('Varenummer') ?>:&nbsp;</div>
                  <div class="field-items"><?php print $node->nid ?> </div>
                </div>
              </div>
              <!-- End - body -->
            <?php //endif; ?>
<?php if (isset($content['add_to_cart_form'])): ?>
    <div class="add-to-cart-form">
      <?php  print render($content['add_to_cart_form']); ?>
    </div>
  <?php endif; ?>
          </div>
          <!-- End - body -->

        </div>

    </div>


  </article>
  <!-- End - teaser -->
