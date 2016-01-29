<?php
/**
 * Implements hook_views_data_alter().
 *
 * Replace field default handler (views_handler_field_field).
 */
function entity_display_field_views_data_alter(&$data) {
  // Get our 'entity_display_field' names;
  $display_fields = field_read_fields(array('type' => 'entity_display_field'));
  
  // If a display field is present in our view, let's find out 
  // what it is called and get its properties.
  if (!empty($display_fields)) {
    foreach ($display_fields as $field_name => $field) {
      $table = _field_sql_storage_tablename($field);
      if (isset($data[$table][$field['field_name']])) {
        $data[$table][$field['field_name']]['field']['handler'] = 'views_handler_entity_display_field';
      }
    }
  }
}