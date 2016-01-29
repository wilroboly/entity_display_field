<?php
/**
 * Field handler to present field title with link to the entity.
 *
 * @ingroup views_field_handlers
 */
class views_handler_entity_display_field extends views_handler_field {

  function option_definition() {
    $options = parent::option_definition();
    return $options;
  }

  /**
   * Provide link to entity option.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
  }

  function render($values) {
    $view_modes = $this->get_view_modes();
    $value = $this->get_value($values);
    if (empty($value)) {
      $keys = array_keys($view_modes);
      $value = array_shift($keys);
    }
    return $view_modes[$this->sanitize_value($value)]['label'];
  }

  // This helper function gets the list of view modes available to the Display Chain
  private function get_view_modes() {
    $base_table = $this->view->base_table;
    $entity_type = $this->definition['entity_tables'][$base_table];
    $entity_info = entity_get_info($entity_type);
    return $entity_info['view modes'];
  }
}
