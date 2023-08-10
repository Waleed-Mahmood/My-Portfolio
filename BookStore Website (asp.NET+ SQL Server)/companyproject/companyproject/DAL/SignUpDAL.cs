using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data;
using System.Data.SqlClient;

namespace companyproject.DAL
{
    public class SignUpDAL
    {
        private static readonly string connString =
        System.Configuration.ConfigurationManager.ConnectionStrings["SQLConnection1"].ConnectionString;

        public int SignUp(String fName, String lName, String pass, Char gender, Char member, String address, String mail)
        {
            SqlConnection con = new SqlConnection(connString);
            int Found = 0;

            if (con.State == ConnectionState.Closed)
            {
                con.Open();
            }
            SqlCommand cmd;
            try
            {
                cmd = new SqlCommand("Register", con);    //name of your procedure
                cmd.CommandType = CommandType.StoredProcedure;

                cmd.Parameters.Add("@FirstName", SqlDbType.VarChar, 30); //defining input parameter
                cmd.Parameters.Add("@LastName", SqlDbType.VarChar, 30);
                cmd.Parameters.Add("@Password", SqlDbType.VarChar, 15);
                cmd.Parameters.Add("@Gender", SqlDbType.Char);
                cmd.Parameters.Add("@Membership", SqlDbType.Char);
                cmd.Parameters.Add("@Address", SqlDbType.VarChar, 50);
                cmd.Parameters.Add("@Email", SqlDbType.VarChar, 30);

                cmd.Parameters.Add("@Result", SqlDbType.Int).Direction = ParameterDirection.Output;

                // set parameter values
                cmd.Parameters["@FirstName"].Value = fName;
                cmd.Parameters["@LastName"].Value = lName;
                cmd.Parameters["@Password"].Value = pass;
                cmd.Parameters["@Gender"].Value = gender;
                cmd.Parameters["@Membership"].Value = member;
                cmd.Parameters["@Address"].Value = address;
                cmd.Parameters["@Email"].Value = mail;

                cmd.ExecuteNonQuery();  //executing stored procedure

                // read output value 
                Found = Convert.ToInt32(cmd.Parameters["@Result"].Value); //convert to output parameter to integer format
                if (Found == 1)  //email already exists
                {
                    HttpContext.Current.Response.Write("<script>alert('Account on this Email already exists.Try another id');</script>");
                }
                else
                {
                    HttpContext.Current.Response.Write("<script>alert('Sign Up Successful. Go to User Login to Login');</script>");
                }
                con.Close();
            }
            catch (SqlException ex)
            {
                Console.WriteLine("SQL Error" + ex.Message.ToString());
                HttpContext.Current.Response.Write("<script>alert('" + ex.Message + "');</script>");
            }
            finally
            {
                con.Close();
            }
            return Found;
        }

        public int SignUpAdmin(String gmail, String fName, String lName, String pass, String cnic)
        {
            SqlConnection con = new SqlConnection(connString);
            int Found = 0;
            if (con.State == ConnectionState.Closed)
            {
                con.Open();
            }
            SqlCommand cmd;
            try
            {
                cmd = new SqlCommand("adminRegister", con);    //name of your procedure
                cmd.CommandType = CommandType.StoredProcedure;

                cmd.Parameters.Add("@gmail", SqlDbType.VarChar, 30);
                cmd.Parameters.Add("@firstName", SqlDbType.VarChar, 30); //defining input parameter
                cmd.Parameters.Add("@lastName", SqlDbType.VarChar, 30);
                cmd.Parameters.Add("@password", SqlDbType.VarChar, 20);
                cmd.Parameters.Add("@cnic", SqlDbType.VarChar, 15);


                cmd.Parameters.Add("@result", SqlDbType.Int).Direction = ParameterDirection.Output;

                // set parameter values
                cmd.Parameters["@firstName"].Value = fName;
                cmd.Parameters["@lastName"].Value = lName;
                cmd.Parameters["@password"].Value = pass;
                cmd.Parameters["@gmail"].Value = gmail;
                cmd.Parameters["@cnic"].Value = cnic;
                cmd.ExecuteNonQuery();  //executing stored procedure
                // read output value 
                Found = Convert.ToInt32(cmd.Parameters["@result"].Value); //convert to output parameter to integer format
                if (Found == 1)  //email already exists
                {
                    HttpContext.Current.Response.Write("<script>alert('Account on this Email already exists.Try another id');</script>");
                }
                else
                {
                    HttpContext.Current.Response.Write("<script>alert('Sign Up Successful. Go to User Login to Login');</script>");
                }
                con.Close();
            }
            catch (SqlException ex)
            {
                Console.WriteLine("SQL Error" + ex.Message.ToString());
                HttpContext.Current.Response.Write("<script>alert('" + ex.Message + "');</script>");
            }
            finally
            {
                con.Close();
            }
            return Found;
        }

        public int UserLogInFunction(String mail, String password)
        {
            SqlConnection con = new SqlConnection(connString);
            int Found = 0;

            if (con.State == ConnectionState.Closed)
            {
                con.Open();
            }
            SqlCommand cmd;
            try
            {
                cmd = new SqlCommand("UserLogIn_Procedure", con);    //name of your procedure
                cmd.CommandType = CommandType.StoredProcedure;

                cmd.Parameters.Add("@mail", SqlDbType.VarChar, 30);    //defining input parameter
                cmd.Parameters.Add("@pass", SqlDbType.VarChar, 30);

                cmd.Parameters.Add("@flag", SqlDbType.Int).Direction = ParameterDirection.Output;

                // set parameter values

                cmd.Parameters["@pass"].Value = password;
                cmd.Parameters["@mail"].Value = mail;

                cmd.ExecuteNonQuery();  //executing stored procedure

                // read output value 
                Found = Convert.ToInt32(cmd.Parameters["@flag"].Value); //convert to output parameter to integer format
                if (Found == 1)  //Matched Successfully
                {
                    HttpContext.Current.Response.Write("<script>alert('User Logged In SUCCESSFULLY :)');</script>");
                    HttpContext.Current.Response.RedirectPermanent("DummyU_Profile.aspx");  //Redirect to Dummy User Profile
                }
                else
                {
                    HttpContext.Current.Response.Write("<script>alert('User LogIn FAILED. INVALID GMAIL OR PASSWORD :(');</script>");
                }
                con.Close();
            }
            catch (SqlException ex)
            {
                Console.WriteLine("SQL Error" + ex.Message.ToString());
                HttpContext.Current.Response.Write("<script>alert('" + ex.Message + "');</script>");
            }
            finally
            {
                con.Close();
            }
            return Found;
        }

        public int AdminLogInFunction(String mail, String password)
        {
            SqlConnection con = new SqlConnection(connString);
            int Found = 0;

            if (con.State == ConnectionState.Closed)
            {
                con.Open();
            }
            SqlCommand cmd;
            try
            {
                cmd = new SqlCommand("AdminLogIn_Procedure", con);    //name of your procedure
                cmd.CommandType = CommandType.StoredProcedure;

                cmd.Parameters.Add("@mail", SqlDbType.VarChar, 30);    //defining input parameter
                cmd.Parameters.Add("@pass", SqlDbType.VarChar, 30);

                cmd.Parameters.Add("@flag", SqlDbType.Int).Direction = ParameterDirection.Output;

                // set parameter values

                cmd.Parameters["@pass"].Value = password;
                cmd.Parameters["@mail"].Value = mail;

                cmd.ExecuteNonQuery();  //executing stored procedure
                // read output value 
                Found = Convert.ToInt32(cmd.Parameters["@flag"].Value); //convert to output parameter to integer format
                if (Found == 1)  //Matched Successfully
                {
                    HttpContext.Current.Response.Write("<script>alert('Admin LogIn SUCCESSFULLY :)');</script>");
                    HttpContext.Current.Response.RedirectPermanent("DummyAdminProfile.aspx");   //Redirects to Dummy Admin Profile
                }
                else
                {
                    HttpContext.Current.Response.Write("<script>alert('Admin LogIn FAILED. INVALID GMAIL OR PASSWORD :(');</script>");
                }
                con.Close();
            }
            catch (SqlException ex)
            {
                Console.WriteLine("SQL Error" + ex.Message.ToString());
                HttpContext.Current.Response.Write("<script>alert('" + ex.Message + "');</script>");
            }
            finally
            {
                con.Close();
            }
            return Found;
        }
        public int checkbooktitleexists(String Title)
        {
            SqlConnection con = new SqlConnection(connString);
            int Found = 0;

            if (con.State == ConnectionState.Closed)
            {
                con.Open();
            }
            SqlCommand cmd;
            try
            {
                cmd = new SqlCommand("searchbooktitle", con);    //name of your procedure
                cmd.CommandType = CommandType.StoredProcedure;

                cmd.Parameters.Add("@title", SqlDbType.VarChar, 30);    //defining input parameter

                cmd.Parameters.Add("@flag", SqlDbType.Int).Direction = ParameterDirection.Output;

                // set parameter values

                cmd.Parameters["@title"].Value = Title;

                cmd.ExecuteNonQuery();  //executing stored procedure
                // read output value 
                Found = Convert.ToInt32(cmd.Parameters["@flag"].Value); //convert to output parameter to integer format
            }
            catch (SqlException ex)
            {
                Console.WriteLine("SQL Error" + ex.Message.ToString());
                HttpContext.Current.Response.Write("<script>alert('" + ex.Message + "');</script>");
            }
            finally
            {
                con.Close();
            }
            return Found;
            
        }
        public double userCart(int iid, int quantity)
        {
            SqlConnection con = new SqlConnection(connString);
            double Found = 0;

            if (con.State == ConnectionState.Closed)
            {
                con.Open();
            }
            SqlCommand cmd;
            try
            {
                cmd = new SqlCommand("cart", con);    //name of your procedure
                cmd.CommandType = CommandType.StoredProcedure;

                cmd.Parameters.Add("@id", SqlDbType.Int); //defining input parameter
                cmd.Parameters.Add("@qt", SqlDbType.Int);
                cmd.Parameters.Add("@flag", SqlDbType.Float).Direction = ParameterDirection.Output;

                // set parameter values
                cmd.Parameters["@id"].Value = iid;
                cmd.Parameters["@qt"].Value = quantity;

                cmd.ExecuteNonQuery();  //executing stored procedure                         
                Found = Convert.ToDouble(cmd.Parameters["@flag"].Value); //convert the output parameter to integer format              

                con.Close();
            }
            catch (SqlException ex)
            {
                Console.WriteLine("SQL Error" + ex.Message.ToString());
                HttpContext.Current.Response.Write("<script>alert('" + ex.Message + "');</script>");
            }
            finally
            {
                con.Close();
            }
            return Found;
        }

        public string getTitle(int iid)
        {
            SqlConnection con = new SqlConnection(connString);

            String thisTitle = "";
            if (con.State == ConnectionState.Closed)
            {
                con.Open();
            }
            SqlCommand cmd;
            try
            {
                cmd = new SqlCommand("retTitle", con);    //name of your procedure
                cmd.CommandType = CommandType.StoredProcedure;

                cmd.Parameters.Add("@id", SqlDbType.Int); //defining input parameter             
                cmd.Parameters.Add("@title", SqlDbType.VarChar, 50).Direction = ParameterDirection.Output;

                // set parameter values
                cmd.Parameters["@id"].Value = iid;
                cmd.ExecuteNonQuery();  //executing stored procedure                         
                thisTitle = Convert.ToString(cmd.Parameters["@title"].Value); //convert the output parameter to integer format
                con.Close();
            }
            catch (SqlException ex)
            {
                Console.WriteLine("SQL Error" + ex.Message.ToString());
                HttpContext.Current.Response.Write("<script>alert('" + ex.Message + "');</script>");
            }
            finally
            {
                con.Close();
            }
            return thisTitle;
        }
}
}
