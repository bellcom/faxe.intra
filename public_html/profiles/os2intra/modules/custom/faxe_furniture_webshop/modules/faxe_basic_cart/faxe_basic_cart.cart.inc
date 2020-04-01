<?php

/**
 * @file
 * Basic cart shopping cart implementation functions.
 */

/**
 * Callback function for cart listing.
 */
function faxe_basic_cart_cart() {
  $cart = faxe_basic_cart_get_cart();
  if (empty($cart)) {
    return t('Your cart is empty.');
  }
  return drupal_get_form('faxe_basic_cart_cart_form');
}

/**
 * Shopping cart form.
 */
function faxe_basic_cart_cart_form() {
  // Getting the shopping cart.
  $cart = faxe_basic_cart_get_cart();
  $checkout_disabled = FALSE;
  // And now the form.
  $form['cartcontents'] = array(
    // Make the returned array come back in tree form.
    '#tree' => TRUE,
    '#prefix' => '<div class="shopping-cart-cart-contents">',
    '#suffix' => '</div>',
  );
  // Cart elements.
  foreach ($cart as $nid => $line_item) {
    $form['cartcontents'][$nid] = array(
      '#type' => 'textfield',
      '#size' => 1,
      '#default_value' => $line_item['faxe_basic_cart_quantity'],
      '#theme' => 'faxe_basic_cart_render_cart_element',
    );
    $product = node_load($nid);
    $stock_amount = (int) $product->field_furniture_stock_amount['und'][0]['value'];
    if ($stock_amount < $line_item['faxe_basic_cart_quantity']) {
      drupal_set_message( t('@product: Unfortunately, only @stock_amount units are available in stock. Please update you shopping cart',  array(
        '@product' => $product->title, '@stock_amount' => $stock_amount)), 'error');
      $checkout_disabled = TRUE;
    }
  }
   // Buttons.
  $form['buttons'] = array(
    // Make the returned array come back in tree form.
    '#tree' => TRUE,
    '#prefix' => '<div class="shopping-cart-checkout row"><div class="col-xs-12">',
    '#suffix' => '</div></div>',
  );
  // Update button.
  $form['buttons']['update'] = array(
    '#type' => 'submit',
    '#value' => t('Update'),
    '#attributes' => array('class' => array('btn btn-primary form-submit')),
  );

  // Checkout button.
  //if (module_exists('faxe_basic_cart_order')) {
    $form['buttons']['checkout'] = array(
      '#type' => 'submit',
      '#disabled' => $checkout_disabled,
      '#value' => t('Checkout'),
      '#attributes' => array('class' => array('btn btn-success form-submit')),
    );
  //////}

  return $form;
}

/**
 * Shopping cart form.
 */
function faxe_basic_cart_cart_form_submit($form_id, $form_state) {
  foreach ($form_state['values']['cartcontents'] as $nid => $value) {
    $quantity = (int) $value;
    if ($quantity > 0) {
      $_SESSION['faxe_shopping_cart']['cart'][$nid]['faxe_basic_cart_quantity'] = $quantity;
    }
    // If the quantity is zero, we just remove the node from the cart.
    elseif ($quantity == 0) {
      unset($_SESSION['faxe_shopping_cart']['cart'][$nid]);
    }
  }
  if ($form_state['values']['op'] == t('Checkout')) {
    drupal_goto('webshop/cart/checkout');
  }
  else {
    drupal_set_message(t('Shopping cart updated.'));
  }
}

/**
 * Callback function for cart/add/.
 *
 * @param int $nid
 *   We are using the node id to store the node in the shopping cart
 */
function faxe_basic_cart_add_to_cart($nid = NULL, $quantity = 1) {
  $nid = (int) $nid;
  $quantity = (int) $quantity;
  if ($nid > 0 && $quantity > 0) {
    if (isset($_SESSION['faxe_shopping_cart']['cart'][$nid])) {
      $_SESSION['faxe_shopping_cart']['cart'][$nid]['faxe_basic_cart_quantity'] += $quantity;
    }
    else {
      $_SESSION['faxe_shopping_cart']['cart'][$nid]['faxe_basic_cart_quantity'] = $quantity;
    }

  drupal_set_message(t('Shopping cart updated.'));
  }
  drupal_goto('/webshop');

}

/**
 * Callback function for cart/remove/.
 *
 * @param int $nid
 *   We are using the node id to remove the node in the shopping cart
 */
function faxe_basic_cart_remove_from_cart($nid = NULL) {
  $nid = (int) $nid;
  if ($nid > 0) {
    unset($_SESSION['faxe_shopping_cart']['cart'][$nid]);
  }
  drupal_set_message(t('Shopping cart updated.'));
  drupal_goto('webshop/cart');
}

/**
 * Function for shopping cart retrieval.
 *
 * @param int $nid
 *   We are using the node id to store the node in the shopping cart
 *
 * @return mixed
 *   Returning the shopping cart contents.
 *   An empty array if there is nothing in the cart
 */
function faxe_basic_cart_get_cart($nid = NULL) {
  if (isset($nid)) {
    return $_SESSION['faxe_shopping_cart']['cart'][$nid];
  }
  if (isset($_SESSION['faxe_shopping_cart']['cart'])) {
    return $_SESSION['faxe_shopping_cart']['cart'];
  }
  // Empty cart.
  return array();
}


/**
 * Shopping cart reset.
 */
function faxe_basic_cart_empty_cart() {
  unset($_SESSION['faxe_shopping_cart']['cart']);
}


/**
 * Theme implementation for rendering the cart element.
 */
function theme_faxe_basic_cart_render_cart_element($variables) {
  // Element name and nid.
  $name = $variables['form']['#name'];
  $nid = (int) str_replace(array('cartcontents[', ']'), '', $name);
  if (empty($nid)) {
    return '';
  }

  // Delete image.
  $vars = array(
    'path' => base_path() . drupal_get_path('module', 'faxe_basic_cart') . '/images/delete.png',
    'alt' => t('Remove from cart'),
    'title' => t('Remove from cart'),
    'attributes' => array('class' => 'shopping-cart-delete-image-image'),
  );
  $delete_link = l(theme('image', $vars), 'webshop/cart/remove/' . $nid, array('html' => TRUE));
  // Getting the node for it's title and description.
  $product = node_load($nid);

  // Prefix.
 // $prefix  = '<div class="shopping-cart-cart-contents">';
  $prefix  = '<div class="row">';
  $prefix .= '  <div class="col-xs-11"><div class="shopping-cart-delete-image">' . $delete_link  . '</div>';
  $prefix .=  '<div class="shopping-cart-title">' . l($product->title, 'node/' . $nid);
  $prefix .= '  </div></div>';
  $prefix .= '  <div class="shopping-cart-quantity col-xs-1">';
  // Suffix.
  $suffix  = '    </div>';
  $suffix .= '  </div>';
 // $suffix .= '</div>';

  // Rendering the element as textfield.
  $quantity = theme('textfield', $variables['form']);
  // Full view return.
  return $prefix . $quantity . $suffix;
}

/**
 * Checkout form implementation.
 */
function faxe_basic_cart_order_checkout() {
  $shopping_cart = faxe_basic_cart_get_cart();

  $options = array(
    'cart' => $shopping_cart,
  );

  // The flat cart (just the listing part).
  $cart = theme('faxe_basic_cart_cart_flat', $options);
  $form = drupal_get_form('faxe_basic_cart_checkout_form');
  // If the cart is empty, we don't want to show the checkout form.
  if (empty($shopping_cart)) {
    return $cart;
  }
  $form_output = '<div class="os2box"><div class="row">';
  $form_output .= '<div class="col-xs-12">' . drupal_render($form) . '</div>';
  $form_output .= '</div>';
  return $cart . $form_output;
}

function faxe_basic_cart_checkout_form($form, &$form_state) {
  global $user;
  $phone = '';
  $user = user_load($user->uid);
  if (isset($form_state['values'])) {
    $values = $form_state['values'];
  }
  if (isset($user->field_os2intra_phone['und']) && !empty($user->field_os2intra_phone['und'])) {
    $phone = $user->field_os2intra_phone['und'][0]['value'];
  }
  $physical_location = '';
  if (!empty($user->field_os2intra_physical_location['und'][0]['target_id'])) {
    $physical_location = taxonomy_term_load($user->field_os2intra_physical_location['und'][0]['target_id'])->name;
  }
  // Getting the shopping cart.
  $form['firstname'] = array(
    '#title' => t('Fornavn'),
    '#type' => 'textfield',
    '#default_value' => (isset($values['firstname'])) ? $values['firstname'] : $user->field_name_first['und'][0]['value'],
    '#required' => TRUE,
  );
  $form['lastname'] = array(
    '#title' => t('Efternavn'),
    '#type' => 'textfield',
    '#default_value' => (isset($values['lastname'])) ? $values['lastname'] : $user->field_name_last['und'][0]['value'],
    '#required' => TRUE,
  );
  $form['email'] = array(
    '#title' => t('E-mail'),
    '#type' => 'textfield',
    '#default_value' => (isset($values['email'])) ? $values['email'] : $user->mail,
    '#required' => TRUE,
  );
  $form['phone'] = array(
    '#title' => t('Telefon'),
    '#type' => 'textfield',
    '#default_value' => (isset($values['phone'])) ? $values['phone'] : $phone,
    '#required' => TRUE,
  );
  
  $form['physical_location'] = array(
    '#title' => t('Fysisk lokation'),
    '#type' => 'textfield',
    '#default_value' => (isset($values['physical_location'])) ? $values['physical_location'] : $physical_location,
    '#required' => TRUE,
  );
  $form['message'] = array(
    '#title' => t('Besked'),
    '#type' => 'textarea',
    '#default_value' => (isset($values['message'])) ? $values['message'] : ''
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit order'),
    '#attributes' => array('class' => array('btn btn-success form-submit'))
  );
  return $form;
}

/**
 * Implements submit of order form.
 *
 * @param $form
 *   A structured array containing the elements and properties of the form.
 * @param $form_state
 *   An array that stores information about the form's current state
 *   during processing.
 */
function faxe_basic_cart_checkout_form_submit($form, &$form_state){
  $values = $form_state['values'];
  $cart = faxe_basic_cart_get_cart();
  $order = new stdClass();
  $order->type = "faxe_furniture_order";
  $order->language = LANGUAGE_NONE;
  node_object_prepare($order);
  $order_title = t('Bestilling') . ' - ' . $values['firstname'] . ' ' . $values['lastname'] . ' - ' . format_date(time(), 'short');
  $order->title = $order_title;
  $order->field_order_person_first_name['und'][0]['value'] = $values['firstname'];
  $order->field_order_person_last_name['und'][0]['value'] = $values['lastname'];
  $order->field_order_person_email['und'][0]['value'] = $values['email'];
  $order->field_order_person_phone['und'][0]['value'] = $values['phone'];
  $order->field_order_person_lokation['und'][0]['value'] = $values['physical_location'];
  $order->field_order_message['und'][0]['value'] = $values['message'];
  node_save($order);

  foreach ($cart as $nid => $line_item) {
    $field_collection_item = entity_create('field_collection_item', array('field_name' => 'field_order_ordered_products'));
    $field_collection_item->setHostEntity('node', $order);
    $field_collection_item->field_ordered_product_ref['und'][]['target_id'] = $nid;
    $field_collection_item->field_ordered_product_code['und'][]['value'] = $nid;
    $field_collection_item->field_ordered_product_quantity['und'][]['value'] = $line_item['faxe_basic_cart_quantity'];
    $field_collection_item->save();
    $product = node_load($nid);
    $product->field_furniture_stock_amount['und'][0]['value'] -= (int)$line_item['faxe_basic_cart_quantity'];
    node_save($product);
  }
  // Send notifications.
  faxe_furniture_webshop_send_order_notifications($order);

  // Empty sopping cart.
  faxe_basic_cart_empty_cart();

  // Redirect to thank you page.
  drupal_goto('webshop/checkout/thank-you');
}