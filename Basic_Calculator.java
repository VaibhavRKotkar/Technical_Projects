// Basic Calculator
import java.lang.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.awt.BorderLayout;
import java.awt.Dimension;
import javax.swing.JLabel;
import java.util.Date;

class MarvellousFrame extends WindowAdapter implements ActionListener
    {
        // Object creation

        Frame fobj = new Frame("Basic Calculator");

        Image icon1 = Toolkit.getDefaultToolkit().getImage("F:\\LB\\Projects\\calculator\\cl.png");
        Date dobj = new Date();

           public Button bAdd = new Button("Add");
           public Button bSub = new Button("Sub");
           public Button bMult = new Button("Mult");
           public Button bDiv = new Button("Div");
           public Button bMod = new Button("Mod");
           public Button bCancel = new Button("Cancel");

            public TextField tDisplay = new TextField();
            public TextField tFno = new TextField();
            public TextField tSno = new TextField();
            public TextField tResult = new TextField();

            Label lNo1 = new Label("First Number");
            Label lNo2 = new Label("Second Number");
            Label lResult = new Label("Result");

         public MarvellousFrame()
         {
                // Frame initialization under constructor:
                fobj.setIconImage(icon1);
                fobj.setLayout(null);
                fobj.setVisible(true);
                fobj.setSize(500,350);
                fobj.addWindowListener(this);
                fobj.setBackground(Color.pink);

                // Buttons initialization (Coordinates) under constructor :
                bAdd.setBounds(50,250,50,20);        // (forward/backward, up/down, width, height)
                bSub.setBounds(110,250,50,20);
                bMult.setBounds(170,250,50,20);
                bDiv.setBounds(230,250,50,20);
                bMod.setBounds(290,250,50,20);
                bCancel.setBounds(350,250,50,20);

                // button colours
                bAdd.setBackground(Color.cyan);
                bSub.setBackground(Color.cyan);
                bMult.setBackground(Color.cyan);
                bDiv.setBackground(Color.cyan);
                bMod.setBackground(Color.cyan);
                bCancel.setBackground(Color.cyan);

                tDisplay.setBackground(Color.orange);

                // Text Field Coordinates:
                tDisplay.setBounds(100,55,250,25);
                tFno.setBounds(200,100,100,20);
                tSno.setBounds(200,140,100,20);
                tResult.setBounds(200,180,100,20);

                // Label Coordinates:
                lNo1.setBounds(50,100,100,20);
                lNo2.setBounds(50,140,100,20);
                lResult.setBounds(50,180,100,20);

                //Adding Buttons to the frame:
                fobj.add(bAdd);
                fobj.add(bSub);
                fobj.add(bMult);
                fobj.add(bDiv);
                fobj.add(bMod);
                fobj.add(bCancel);

                // Adding Text Fields to the frame:
                fobj.add(tDisplay);
                fobj.add(tFno);
                fobj.add(tSno);
                fobj.add(tResult);

                // Adding Labels to the frame:
                fobj.add(lNo1);
                fobj.add(lNo2);
                fobj.add(lResult);

                // Components ne listen kele pahije (Implement ActionListener)
                bAdd.addActionListener(this);
                bSub.addActionListener(this);
                bMult.addActionListener(this);
                bDiv.addActionListener(this);
                bMod.addActionListener(this);
                bCancel.addActionListener(this);
         }

         public void windowClosing(WindowEvent obj)
            {
                System.exit(0);
            }

            public void actionPerformed(ActionEvent obj)
            {

                 int iNo1 = Integer.parseInt(tFno.getText());
                 int iNo2 = Integer.parseInt(tSno.getText());

                     if(obj.getSource() == bAdd)
                        {
                            tResult.setText(String.valueOf(iNo1 + iNo2));
                             tDisplay.setText("Addition"+"   " +dobj);
                        }
                     if(obj.getSource() == bSub)
                        {
                            tResult.setText(String.valueOf(iNo1 - iNo2));
                            tDisplay.setText("Subtraction"+"   " +dobj);
                        }
                     if(obj.getSource() == bMult)
                        {
                            tResult.setText(String.valueOf(iNo1 * iNo2));
                            tDisplay.setText("Multiplication"+"   " +dobj);
                        }
                     if(obj.getSource() == bDiv)
                        {
                            tResult.setText(String.valueOf(iNo1 / iNo2));
                            tDisplay.setText("Division"+"   " +dobj);
                        }

                     if(obj.getSource() == bMod)
                        {
                            tResult.setText(String.valueOf(iNo1 % iNo2));
                            tDisplay.setText("Remainder"+"   " +dobj);
                        }

                     if(obj.getSource() == bCancel)
                        {
                            System.exit(0);
                        }
            }
 }

class Calculator
{
    public static void main(String arg[])
    {
          System.out.println("Print the data on Console");
         MarvellousFrame mobj = new MarvellousFrame ();
    }
}