// Database Management system in java using linkedlist using tokenization or Query parsing
//DBMS
import java.lang.*;
import java.util.*;
import java.io.IOException;


///////////////////////////////////////////////////
// Class Name:    Student
// Description:   Database table / Schema
// Function1:     Constructor
// Function2:      Display Data
///////////////////////////////////////////////////
class Student
{
    public int RID;
    public String Name;
    public int Salary;

    private static int Generator;

    static
    {
      Generator = 0;
    }

    public Student(String str, int value)
    {
        this.RID = ++Generator;
        this.Name = str;
        this.Salary = value;
    }
    public void DisplayData()
    {
       System.out.println(this.RID+"\t"+this.Name+"\t\t"+this.Salary);
    }
}

///////////////////////////////////////////////////
// Class Name:    DBMS
// Description:   Database functionalities
///////////////////////////////////////////////////

class DBMS
{
    LinkedList<Student> lobj;

    public DBMS()
    {
        lobj = new LinkedList<>();
    }
///////////////////////////////////////////////////////////
//
// Function Name: StartDBMS
// Description:   Used to Start DBMS Console
// Input:         Nothing
// Output:        Nothing

///////////////////////////////////////////////////////////
    public void StartDBMS()
    {
        Scanner scanobj = new Scanner(System.in);

        System.out.println(" Customised DBMS started successfully...");
        System.out.println(" (For More Information Enter : Help)");

        String Query = "";

        while(true)
        {
            System.out.print(" DBMS Console > ");
            Query = scanobj.nextLine();
            Query = Query.toLowerCase();

            String tokens[] = Query.split(" ");
            int QuerySize = tokens.length;

            if(QuerySize == 1)
            {
                if("help".equals(tokens[0]))
                {
                     System.out.println("  This Application is used to demonstrate the customised DBMS");
                     System.out.println("1. Table Name: student");
                     System.out.println("2. Exit : Terminate DBMS");
                     System.out.println("3. Clear : Clear DBMS screen");
                     System.out.println("4. Display all Data: select * from student");
                     System.out.println("5. Insert Data: Insert into student Name Salary");
                     System.out.println("6. Delete Specific Data: Delete from student where CONDITION(CONDITION : Name = name / RID = rid)");
                     System.out.println("7. Display Specific Data: select CONDITION from student(CONDITION : Name = name / RID = rid) ");
                     System.out.println("8. Maximum Data: select Max Salary from student");
                     System.out.println("9. Minimum Data: select Min Salary from student");
                     System.out.println("10. Summation of Data: select Sum Salary from student");
                     System.out.println("11. Average of Data: select Avg Salary from student");
                     System.out.println("12. Count Data Entry: select Count Salary/Name/RID from student");
                     System.out.println("13. Update Specific Data: update student set CONDITION where RID = value");
                }
                else if("exit".equals(tokens[0]))
                {
                    System.out.println("Thank you for using Virtual DBMS");
                    break;
                }
                else if("clear".equals(tokens[0]))
                {
                     ClearConsole();
                }
            }
            else if(QuerySize == 2)
            {

            }
            else if(QuerySize == 4)
            {
                if("select".equals(tokens[0]))
                {
                    if("*".equals(tokens[1]))
                    {
                        if("from".equals(tokens[2]))
                         {
                             if("student".equals(tokens[3]))
                             {
                                DisplayAll();
                             }
                             else {  System.out.println("Invalid Table Name"); }
                         } else {  System.out.println("Invalid Query"); }
                    }
                }
            }
            else if(QuerySize == 5)
            {
                if("insert".equals(tokens[0]))
                {
                    if("into".equals(tokens[1]))
                    {
                        if("student".equals(tokens[2]))
                        {
                            InsertData(tokens[3],Integer.parseInt(tokens[4]));
                        } else {System.out.println("Invalid Table Name");}
                    } else {System.out.println("Invalid Query");}
                }
                else if("select".equals(tokens[0]))
                {
                    if("max".equals(tokens[1]))
                    {
                        if("salary".equals(tokens[2]))
                        {
                              if("from".equals(tokens[3]))
                              {
                                  if("student".equals(tokens[4]))
                                  {
                                     AggregateMax();
                                  } else {System.out.println("Invalid Table Name");}
                              } else {System.out.println("Invalid Query");}
                        }else {System.out.println("Operation invalid on this column");}
                    }
                    else if("min".equals(tokens[1]))
                    {
                        if("salary".equals(tokens[2]))
                        {
                              if("from".equals(tokens[3]))
                              {
                                  if("student".equals(tokens[4]))
                                  {
                                     AggregateMin();
                                  } else {System.out.println("Invalid Table Name");}
                              } else {System.out.println("Invalid Query");}
                        } else {System.out.println("Operation invalid on this column");}
                    }
                    else if("sum".equals(tokens[1]))
                    {
                        if("salary".equals(tokens[2]))
                        {
                              if("from".equals(tokens[3]))
                              {
                                  if("student".equals(tokens[4]))
                                  {
                                     AggregateSum();
                                  } else {System.out.println("Invalid Table Name");}
                              } else {System.out.println("Invalid Query");}
                        } else {System.out.println("Operation invalid on this column");}
                    }
                    else if("avg".equals(tokens[1]))
                    {
                        if("salary".equals(tokens[2]))
                        {
                              if("from".equals(tokens[3]))
                              {
                                  if("student".equals(tokens[4]))
                                  {
                                     AggregateAvg();
                                  } else {System.out.println("Invalid Table Name");}
                              } else {System.out.println("Invalid Query");}
                        } else {System.out.println("Operation invalid on this column");}
                    }
                    else if("count".equals(tokens[1]))
                    {
                        if("salary".equals(tokens[2]))
                        {
                              if("from".equals(tokens[3]))
                              {
                                  if("student".equals(tokens[4]))
                                  {
                                     AggregateCount();
                                  } else {System.out.println("Invalid Table Name");}
                              } else {System.out.println("Invalid Query");}
                        }
                        else if("name".equals(tokens[2]))
                        {
                              if("from".equals(tokens[3]))
                              {
                                  if("student".equals(tokens[4]))
                                  {
                                     AggregateCount();
                                  } else {System.out.println("Invalid Table Name");}
                              } else {System.out.println("Invalid Query");}
                        }
                        else if("rid".equals(tokens[2]))
                        {
                              if("from".equals(tokens[3]))
                              {
                                  if("student".equals(tokens[4]))
                                  {
                                     AggregateCount();
                                  } else {System.out.println("Invalid Table Name");}
                              } else {System.out.println("Invalid Query");}
                        }else {System.out.println("Operation invalid on this column");}
                    }
                }
            }
           else if(QuerySize == 6)
            {
                if("select".equals(tokens[0]))
                {
                    if("name".equals(tokens[1]))
                    {
                        if("=".equals(tokens[2]))
                        {
                            if("from".equals(tokens[4]))
                            {
                                if("student".equals(tokens[5]))
                                {
                                    DisplaySpecific(tokens[3]);
                                } else {System.out.println("Invalid Table Name");}
                            }
                        } else {System.out.println("Invalid Query");}
                    }
                    else if("rid".equals(tokens[1]))
                    {
                         if("=".equals(tokens[2]))
                        {
                            if("from".equals(tokens[4]))
                            {
                                if("student".equals(tokens[5]))
                                {
                                    DisplaySpecific(Integer.parseInt(tokens[3]));
                                } else {System.out.println("Invalid Table Name");}
                            }
                        } else {System.out.println("Invalid Query");}
                    } else {System.out.println("Invalid column name");}
                }
            }
            else if(QuerySize == 7)
            {
                if("delete".equals(tokens[0]))
                {
                    if("from".equals(tokens[1]))
                    {
                        if("student".equals(tokens[2]))
                        {
                           if("where".equals(tokens[3]))
                           {
                                if("name".equals(tokens[4]))
                                {
                                     if("=".equals(tokens[5]))
                                     {
                                        DeleteSpecific(tokens[6]);
                                     } else {System.out.println("Invalid Query");}
                                }
                                else if("rid".equals(tokens[4]))
                                {
                                    if("=".equals(tokens[5]))
                                     {
                                        DeleteSpecific(Integer.parseInt(tokens[6]));
                                     } else {System.out.println("Invalid Query");}
                                } else {System.out.println("Invalid column name");}
                           } else {System.out.println("Invalid Query");}
                        } else {System.out.println("Invalid Table Name");}
                    } else {System.out.println("Invalid Query");}
                }
            }
            else if(QuerySize == 10)
            {
                if("update".equals(tokens[0]))
                {
                     if("student".equals(tokens[1]))
                     {
                        if("set".equals(tokens[2]))
                        {
                            if("name".equals(tokens[3]))
                            {
                                if("=".equals(tokens[4]))
                                {
                                     if("where".equals(tokens[6]))
                                     {
                                        if("rid".equals(tokens[7]))
                                        {
                                            if("=".equals(tokens[8]))
                                            {
                                                UpdateData(tokens[5],Integer.parseInt(tokens[9]));
                                            }
                                        }else {System.out.println("Invalid Query");}
                                     } else {System.out.println("Invalid Query");}
                                }else {System.out.println("Invalid Query");}
                            }
                            else if("salary".equals(tokens[3]))
                            {
                                   if("=".equals(tokens[4]))
                                {
                                     if("where".equals(tokens[6]))
                                     {
                                        if("rid".equals(tokens[7]))
                                        {
                                            if("=".equals(tokens[8]))
                                            {
                                                UpdateData(Integer.parseInt(tokens[5]),Integer.parseInt(tokens[9]));
                                            }
                                        }else {System.out.println("Invalid Query");}
                                     } else {System.out.println("Invalid Query");}
                                }else {System.out.println("Invalid Query");}
                            } else {System.out.println("Invalid column name");}
                        } else {System.out.println("Invalid Query");}
                     } else {System.out.println("Invalid Table Name");}
                }
            }
        }
    }

///////////////////////////////////////////////////////////
//
// Function Name:  InsertData
// Description:   Used to Insert Data into Database
// Input:         String, Integer
// Output:        Nothing

///////////////////////////////////////////////////////////

    public void InsertData(String str, int value)
    {
        Student sobj =  new Student(str,value);
        lobj.add(sobj);
    }

///////////////////////////////////////////////////////////
//
// Function Name:  DisplayAll
// Description:   Used to Display Data Table
// Input:         Nothing
// Output:        Nothing

///////////////////////////////////////////////////////////
    public void DisplayAll()
    {
       System.out.println("--------------------------------------------------");
       System.out.println("RID"+"\t"+"Name"+"\t\t"+"Salary");
       System.out.println("--------------------------------------------------");
        for(Student sref : lobj)   // for each loop
        {
            sref.DisplayData();
        }
         System.out.println("--------------------------------------------------");
    }
/////////////////////////////////////////////////////////////////////
//
// Function Name:  DisplaySpecific
// Description:   Used to Display specific Data from Table using RID
// Input:         Integer
// Output:        Nothing

//////////////////////////////////////////////////////////////////////
     public void DisplaySpecific(int rid)
     {
       System.out.println("--------------------------------------------------");
       System.out.println("RID"+"\t"+"Name"+"\t\t"+"Salary");
       System.out.println("--------------------------------------------------");
        for(Student sref : lobj)   // for each loop
        {
            if(sref.RID == rid)
            {
                sref.DisplayData();
                break;
            }
        }
        System.out.println("--------------------------------------------------");
     }
/////////////////////////////////////////////////////////////////////
//
// Function Name:  DisplaySpecific
// Description:   Used to Display specific Data from Table using Name
// Input:         String
// Output:        Nothing

//////////////////////////////////////////////////////////////////////
      public void DisplaySpecific(String str)
     {
       System.out.println("--------------------------------------------------");
       System.out.println("RID"+"\t"+"Name"+"\t\t"+"Salary");
       System.out.println("--------------------------------------------------");
        for(Student sref : lobj)   // for each loop
        {
            if(str.equals(sref.Name))
            {
                sref.DisplayData();
            }
        }
        System.out.println("--------------------------------------------------");
     }

/////////////////////////////////////////////////////////////////////
//
// Function Name:  DeleteSpecific
// Description:   Used to Delete specific Data from Table using RID
// Input:         Integer
// Output:        Nothing

//////////////////////////////////////////////////////////////////////

     public void DeleteSpecific(int rid)
     {
        int index = 0;
        for(Student sref : lobj)   // for each loop
        {
            if(sref.RID == rid)
            {
                lobj.remove(index);
                break;
            }
            index++;
        }
     }

/////////////////////////////////////////////////////////////////////
//
// Function Name:  DeleteSpecific
// Description:   Used to Delete specific Data from Table using Name
// Input:         String
// Output:        Nothing

//////////////////////////////////////////////////////////////////////

   public void DeleteSpecific(String str)
     {
        int index = 0;
        for(Student sref : lobj)   // for each loop
        {
            if(str.equals(sref.Name))
            {
                lobj.remove(index);
            }
            index++;
        }
     }
/////////////////////////////////////////////////////////////////////
//
// Function Name:  AggregateMax
// Description:   Used to display Maximum Salary Data from Table
// Input:         Nothing
// Output:        Nothing

//////////////////////////////////////////////////////////////////////
     public void AggregateMax()
     {
      int iMax = 0;
      Student temp = null;

      for(Student sref : lobj)
      {
        if(sref.Salary > iMax)
        {
            iMax = sref.Salary;
            temp = sref;
        }
      }
      System.out.println("Information of student having Maximum Salary : ");
      System.out.println("--------------------------------------------------");
         temp.DisplayData();
      System.out.println("--------------------------------------------------");
     }
/////////////////////////////////////////////////////////////////////
//
// Function Name:  AggregateMin
// Description:   Used to display Minimum Salary Data from Table
// Input:         Nothing
// Output:        Nothing

//////////////////////////////////////////////////////////////////////
    public void AggregateMin()
     {
      int iMin = (lobj.getFirst()).Salary;  // initialization imp
      Student temp = lobj.getFirst();   // initialization imp

      for(Student sref : lobj)   // sref is reference of student
      {
        if(sref.Salary < iMin)
        {
            iMin = sref.Salary;
            temp = sref;
        }
      }
      System.out.println("Information of student having Minimum Salary : ");
       System.out.println("--------------------------------------------------");
         temp.DisplayData();
       System.out.println("--------------------------------------------------");
     }
/////////////////////////////////////////////////////////////////////
//
// Function Name:  AggregateSum
// Description:   Used to display Summation of Salary.
// Input:         Nothing
// Output:        Nothing

//////////////////////////////////////////////////////////////////////
    public void AggregateSum()
    {
        long iSum = 0;

      for(Student sref : lobj)   // sref is reference of student
      {
       iSum = iSum + sref.Salary;
      }
       System.out.println("------------------------------------");
       System.out.println("Summation of Salaries is : "+ iSum);
       System.out.println("------------------------------------");
    }
/////////////////////////////////////////////////////////////////////
//
// Function Name:  AggregateAvg
// Description:   Used to display Average of Salary.
// Input:         Nothing
// Output:        Nothing

//////////////////////////////////////////////////////////////////////
    public void AggregateAvg()
    {
        long iSum = 0;

      for(Student sref : lobj)   // sref is reference of student
      {
       iSum = iSum + sref.Salary;
      }
       System.out.println("------------------------------------");
       System.out.println("Average Salaries is : "+ iSum / (lobj.size()));
       System.out.println("------------------------------------");
    }
/////////////////////////////////////////////////////////////////////
//
// Function Name:  AggregateCount
// Description:   Used to count Entries.
// Input:         Nothing
// Output:        Nothing

//////////////////////////////////////////////////////////////////////

    public void AggregateCount()
    {
        System.out.println("------------------------------------");
        System.out.println("Student Count is : "+lobj.size());
        System.out.println("------------------------------------");
    }
/////////////////////////////////////////////////////////////////////
//
// Function Name:  UpdateData
// Description:   Update name of Specific Entry.
// Input:         String, Integer
// Output:        Nothing
//
//////////////////////////////////////////////////////////////////////
    public void UpdateData(String str,int rid)
    {
      for(Student sref : lobj)   // sref is reference of student
      {
        if (sref.RID == rid)
        {
            sref.Name = str;
            break;
        }
      }
    }

/////////////////////////////////////////////////////////////////////
//
// Function Name:  UpdateData
// Description:   Update Salary of Specific Entry.
// Input:         Integer, Integer
// Output:        Nothing
//
//////////////////////////////////////////////////////////////////////
    public void UpdateData(int salary,int rid)
    {
      for(Student sref : lobj)   // sref is reference of student
      {
        if (sref.RID == rid)
        {
            sref.Salary = salary;
            break;
        }
      }
    }

/////////////////////////////////////////////////////////////////////
//
// Function Name:  ClearConsole
// Description:   Clears DBMS Screen.
// Input:         Nothing
// Output:        Nothing

//////////////////////////////////////////////////////////////////////
    public static void ClearConsole()
    {
        try
        {
            if (System.getProperty("os.name").contains("Windows"))
                { new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor(); }
            else
               { Runtime.getRuntime().exec("clear"); }
        }
         catch (IOException | InterruptedException eobj)
         { System.out.println(eobj);}
    }
}

///////////////////////////////////////////////////
// Function Name: main
// Description:   Entry Point Function
// Input:         Nothing
// Output:        Integer
///////////////////////////////////////////////////

class program374
{
  public static void main(String args[])
  {
        DBMS dobj = new DBMS();
        dobj.StartDBMS();
  }
}