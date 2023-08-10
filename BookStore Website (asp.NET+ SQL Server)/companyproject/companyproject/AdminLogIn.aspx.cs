using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using companyproject.DAL;
using System.Data;


namespace companyproject
{
    public partial class  AdminLogIn : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }
        protected void AdminLogin_Button_Click(object sender, EventArgs e)
        {

            //Trim method that trims a string from both ends by removing white spaces or a specified character or characters from the start and the end of a string.

            String mail = TextBox3.Text.Trim();
            String password = TextBox4.Text.Trim();

            //check if any text box is empty or not
            if (String.IsNullOrEmpty(password) || String.IsNullOrEmpty(mail))
            { }
            else
            {
                if (!(mail.Contains("@")))
                {
                    Response.Write("<script>alert('Enter valid email address. Must include '@');</script>");
                }

                if (!(mail.Contains(".com")) || !(mail.Contains("com")))
                {
                    Response.Write("<script>alert('Enter valid email address. Must end with'.com');</script>");
                }

                else
                {
                    SignUpDAL objMyDal = new SignUpDAL();
                    int found;
                    found = objMyDal.AdminLogInFunction(mail, password);
                }

            }
        }
    }
}
