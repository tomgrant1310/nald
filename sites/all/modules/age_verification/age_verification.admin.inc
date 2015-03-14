<?php

/**
 * @file
 * Age Verification administration functions.
 */

/**
 * Form constructor for Age Verification settings.
 */
function age_verification_admin_form($form, &$form_state) {
  $form['age'] = array(
    '#type' => 'select',
    '#title' => t('Age Limit'),
    '#options' => array(
      21 => t('21'),
      20 => t('20'),
      19 => t('19'),
      18 => t('18'),
      17 => t('17'),
      16 => t('16'),
      15 => t('15'),
      14 => t('14'),
    ),
    '#default_value' => variable_get('age_verification_selected', ''),
    '#description' => t('Set this to the age limit you require.'),
  );
  $form['urls'] = array(
    '#type' => 'textarea',
    '#title' => t('Relative URLs'),
    '#rows' => 3,
    '#cols' => 20,
    '#default_value' => variable_get('age_verification_urls', ''),
    '#description' => t('Enter the node relative urls of the pages that the age verification should ignore. In example, user or node/62 or cookie-policy. One per line.'),
  );

  $form['description'] = array(
    '#type' => 'textarea',
    '#title' => t('Form description'),
    '#rows' => 3,
    '#cols' => 20,
    '#default_value' => variable_get('age_verification_description', ''),
    '#description' => t('Add any description information or links you want to display under the form. Links & HTML tags: are allowed.'),
  );

  $form['#submit'][] = 'age_verification_admin_form_submit';
  return system_settings_form($form);

}
/**
 * Variable_set form submit action.
 */
function age_verification_admin_form_submit($form, &$form_state) {
  variable_set('age_verification_selected', $form_state['values']['age']);
  variable_set('age_verification_urls', $form_state['values']['urls']);
  variable_set('age_verification_description', $form_state['values']['description']);
}
