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
    $value = $this->get_value($values);
    return $this->sanitize_value($value);
  }
}
