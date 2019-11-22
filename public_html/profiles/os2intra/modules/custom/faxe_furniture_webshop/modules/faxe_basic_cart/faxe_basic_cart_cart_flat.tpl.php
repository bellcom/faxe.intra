<?php
/**
 * @file
 * Basic cart shopping cart html template
 */
?>

<?php if (empty($cart)): ?>
  <p><?php print t('Your shopping cart is empty.'); ?></p>
<?php else: ?>
  <div class="shopping-cart-block-flat">
    <div class="shopping-cart-cart-contents">
    <?php if(is_array($cart)): ?>
      <?php foreach($cart as $nid => $item_line): ?>
        <?php $product = node_load($nid); ?>
          <div class="row">
           <div class="shopping-cart-node-title col-xs-10">
            <?php print l($product->title, 'node/' . $product->nid); ?>
          </div>
           <div class="shopping-cart-quantity col-xs-2"><?php print $item_line['faxe_basic_cart_quantity']; ?></div>
        </div>
        </div>
      <?php endforeach; ?>
    </div>
   <?php endif; ?>
 <?php endif; ?>
