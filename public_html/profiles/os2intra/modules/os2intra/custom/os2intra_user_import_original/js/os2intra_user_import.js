/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
(function ($) {
  Drupal.behaviors.os2intraUserImport = {
    attach: function (context, settings) {
      $('.os2intra-mapping-fallback-field').each(function( index ){
         if ($(this).val() == 'input') {
          $(this).parent('.form-item').next('.form-item').children('input[type="text"]').css('visibility', 'visible');
        }
        else {
          $(this).parent('.form-item').next('.form-item').children('input[type="text"]').css('visibility', 'hidden');
        }
      });
      $('.os2intra-mapping-fallback-field').change(function (event) {
        if ($(this).val() == 'input') {
          $(this).parent('.form-item').next('.form-item').children('input[type="text"]').css('visibility', 'visible');
        }
        else {
          $(this).parent('.form-item').next('.form-item').children('input[type="text"]').css('visibility', 'hidden');
        }
      });
       $('.os2intra-mapping-primary-field').change(function (event) {
          $('.os2intra-mapping-markup-field').hide();
      });

    }
  }
})(jQuery);

