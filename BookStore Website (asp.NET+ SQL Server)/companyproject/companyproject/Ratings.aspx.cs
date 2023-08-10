using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace companyproject
{
    public partial class Ratings : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            string a = Convert.ToString(Request.QueryString["id"]);
            SQLConnectioncommand.SelectParameters.Add("bookid", System.Data.DbType.Int32, a);
            Reviews123.SelectParameters.Add("bookid", System.Data.DbType.Int32, a);
            SQLConnectioncommand.SelectCommand = "select * from Books where BookID=@bookid";
            Reviews123.SelectCommand = "select * from Reviews join Users on Users.UserID=Reviews.UserID where Reviews.BookID=@bookid";

        }
    }
}