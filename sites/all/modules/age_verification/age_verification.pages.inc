<?php

/**
 * @file
 * Age Verification form page functions.
 */
 
 /**
  * Implements hook_form(). 
  * 
  * Custom age verification form.
  */
function age_verification_form($form, &$form_state) {
  $form['#theme'] = 'agil_list_form';
  $form['dob'] = array(
    '#title' => t('Please enter your date of birth'),
    '#type' => 'date',
    '#default_value' => (!empty($form_state['values']['dob'])) ? $form_state['values']['dob'] : array(),
    '#required' => TRUE,
  );
  $form['confirmation'] = array(
    '#type' => 'checkbox',
    '#title' => "I confirm that this is my age",
    '#required' => TRUE,
  );
  // Output the admin description text in the form.
  $form['custom_age_verification_description'] = array(
    '#type' => 'markup',
    '#markup' => '<p>' . filter_xss(variable_get('age_verification_description')) . '</p>',
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
  );

  return $form;
}

  /**
   * Implements hook_form_validate().
   * 
   * On Submit we verify data and the age is correct before passing it on 
   * to the submit function.
   */
function age_verification_form_validate($form, &$form_state) {
  $form_values = $form_state['values'];

  if (isset($form_values['dob']['month'])) {
    // Get rid of future dates.
    if ($form_values['dob']['year'] > date('Y')) {
      $form_values['dob']['year'] = date('Y');
    }
    // Lets add the now DateTime to $date_now
    $date_now = new DateTime("now");
    // Form values of day month year are a datetime added to $date_posted.
    $date_posted = new DateTime($form_values['dob']['year'] . '-' . $form_values['dob']['month'] . '-' . $form_values['dob']['day']);
    // Date now is less diff $date_posted lets add to $difference.
    $difference = $date_now->diff($date_posted);
    $difference = $difference->format('%y');
    // Add the Age to $accepted_age with a default of 21.
    $accepted_age = variable_get('age_verification_selected', 21);
    // Compare the accepted_age with years of difference.
    if ($difference <= $accepted_age) {
      // Throw an error if user age is less than the age selected.
      // !variable: Inserted as is, with no sanitization or formatting.
      form_set_error('dob', t('You need to be !age or over to access the site.', array('!age' => $accepted_age)));
    }
  }
  // Throw an error if user has not selected T&Cs.
  if ((int) @$form_values['confirmation'] != 1) {
    form_set_error('confirmation', t('You need to accept Terms & Conditions.'));
  }
}

  /**
   * Implements hook_form_submit().
   * 
   * On Submit we add verified to age_verified and add that to the session.
   */
function age_verification_form_submit($form, &$form_state) {
  // Add TRUE to session age_verified.
  $_SESSION['age_verified'] = TRUE;
}
