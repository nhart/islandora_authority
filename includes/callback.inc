<?php

/**
 * @file
 * Autocomplete callback and friends.
 */

/**
 * Page/autocomplete callback to grab results from Solr.
 */
function islandora_authority_autocomplete($build_id, $element, $string = '') {
  drupal_json_output(
    IslandoraAuthorityAbstractController::createFromBuildAndHash($build_id, $element)->search($string)
  );
}

/**
 * Callback to validate the contents of an autocomplete field against Solr.
 */
function islandora_authority_validate($build_id, $element, $string = '') {
  drupal_json_output(array(
    'match' => IslandoraAuthorityAbstractController::createFromBuildAndHash($build_id, $element)->validate($string),
  ));
}
