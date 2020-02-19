<?php
/**
 * @file
 * Basic cart shopping cart block
 */
?>

<?php if (empty($cart)): ?>
  <p><?php print t('Your cart is empty.'); ?></p>
<?php else: ?>
  <div class="shopping-cart-block">
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
      <?php endforeach; ?>
      </div>
       <div class="shopping-cart-checkout row">
        <div class="col-xs-12">
          <?php print l(t('View cart'), 'webshop/cart', array('attributes' => array('class' => array('button btn-checkout')))); ?>
        </div>
      </div>
     <?php endif; ?>
  </div>
<?php endif; ?>
