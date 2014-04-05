<?php
/**
 * @file
 * This contains all the magic we need to rock our custom layout builder
 */

/**
 * Implements hook_ctools_plugin_pre_alter
 *
 * this file needs to be loaded during ajax
 *
 */
function kalatheme_ctools_plugin_type_alter(&$types) {
  // Override a function defined by the plugin.
  // Allow themes to load display_renderers
  $types['panels']['display_renderers']['load themes'] = TRUE;
}

/**
 * Implements hook_panels_ipe_region_links_alter().
 */
function kalatheme_panels_ipe_region_links_alter(&$vars, &$context) {
  if ($context['display']->layout === 'kalatheme' && $context['region_id'] === 'global') {
    unset($vars['add-pane']);
  }
  if ($context['display']->layout === 'kalatheme') {
    $button = array(
      'title' => '<span>Add Column</span>',
      'href' => 'panels/ajax/kalatheme/add-col/' . $context['display']->cache_key . '/region/' . $context['region_id'],
      'html' => TRUE,
      'attributes' => array(
        'class' => array('ctools-use-modal', 'panels-ipe-hide-bar'),
        'title' => 'Add Column',
      ),
    );
    $vars['columns'] = $button;
  }
}

