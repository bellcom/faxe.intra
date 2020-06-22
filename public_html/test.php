<?php

/* 
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
$data = '<div class="t m0 x1 h2 y2 ff1 fs0 fc0 sc0 ls0 ws0"> <span class="_ _1"> </span><span class="fs1">Sagsnummer.: 19/20711 </span></div>'
    . '<div class="t m0 x1 h2 y2 ff1 fs0 fc0 sc0 ls0 ws0"> <span class="_ _1"> </span><span class="fs1">Sagsnummer.: 19/20711 </span></div>'
    . '<div class="t m0 x1 h2 y2 ff1 fs0 fc0 sc0 ls0 ws0"> <span class="_ _1"> </span><span class="fs1">Sagsnummer.: 19/20711 </span></div>'
    . '<div class="t m0 x1 h2 y2 ff1 fs0 fc0 sc0 ls0 ws0"> <span class="_ _1"> </span><span class="fs1">Sagsnummer.: 19/20711 </span></div>';

preg_match_all('/<div (class.+?fc0.+?)>.*?(<\/div>)/is', $data, $matches, PREG_SET_ORDER, 0);
var_dump($matches);
  // Foreach <a> tag.
  foreach ($matches as $match) {
    $match = reset($match);
    // Get link text.
        $str = str_replace('fc0', "", $match);
      $data = str_replace($match, $str, $data);
  }
  var_dump($data);
    