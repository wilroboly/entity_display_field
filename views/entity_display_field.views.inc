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
    //dd($display_fields, 'DISPLAY FIELDS');
    foreach ($display_fields as $field_name => $field) {
      $table = _field_sql_storage_tablename($field);
      // dd($field_name, 'FIELD NAME');
      // dd($field, 'FIELD');
      // dd($table, 'TABLE');
      if (isset($data[$table][$field['field_name']])) {
        $data[$table][$field['field_name']]['field']['handler'] = 'views_handler_entity_display_field';
      }
      // dd($data[$table][$field['field_name']], 'DATA FIELD NAME');
    }
  }
  //
  // foreach (entity_get_info() as $info) {
  //   if ($info['label'] == 'Chains') {
  //     dd(array_keys($info), 'keys');
  //     dd($info, 'INFO');
  //   }
  //   if (isset($info['uuid']) && $info['uuid'] == TRUE && !empty($info['entity keys']['uuid'])) {
  //
  //   }
  // }
  // $field = field_info_field('field_data_field_display_view_mode');
  // dd($field, 'FIELD');
  // $table = _field_sql_storage_tablename($field);
  // if (isset($data[$table][$field['field_name']])) {
  //   $data[$table][$field['field_name']]['field']['handler'] = 'views_handler_entity_display_field';
  // }
}