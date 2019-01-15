package edu.ufl.cise.os.p2;

import android.os.Bundle;
import android.text.Editable;
import android.text.SpannableStringBuilder;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.app.Activity;

    public class P2Activity extends Activity {

        // Used to load the 'native-lib' library on application startup.
        static {
            System.loadLibrary("native-lib");
        }
        private Button submitButton;
        private EditText filenameBox, displaybox;

        @Override
        protected void onCreate(Bundle savedInstanceState) {
            super.onCreate(savedInstanceState);
            setContentView(R.layout.activity_p2);

            // Example of a call to a native method
            //TextView tv = (TextView) findViewById(R.id.displayBox);
            //tv.setText(stringFromJNI());
            submitButton = (Button) findViewById(R.id.submitButton);
            filenameBox = (EditText) findViewById(R.id.filenameBox);


        }

        public void submitButtonClick(View view)
        {
            TextView tv = (TextView) findViewById(R.id.displayBox);

            //retrieve the filename from the filenameBox
            Editable fname = filenameBox.getText();
            //change filename to a string variable
            String newString = fname.toString();

            //displayBox.setText("hello world this is a test");



            //String ret_value = read_file(newString);    //THIS IS THE LINE TO CHANGE

                                                        //EDIT THIS LINE TO CALL THE read_file method
            //String testing = stringFromJNI(newString);
            //Editable fin_val = new SpannableStringBuilder(testing);
            tv.setText(stringFromJNI(newString));
              //finally display the file contents inside of displayBox

        }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI(String s);
}
