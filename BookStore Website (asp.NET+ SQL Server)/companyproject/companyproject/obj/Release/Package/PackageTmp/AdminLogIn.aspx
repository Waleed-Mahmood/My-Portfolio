<%@ Page Title="" Language="C#" MasterPageFile="~/bookstore.Master" AutoEventWireup="true" CodeBehind="AdminLogIn.aspx.cs" Inherits="companyproject.AdminLogIn" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
    <h3 id="bolde">ADMIN LOGIN: </h3>
    <div class="tm-container-inner-2 tm-contact-section">
        <div class="row">
            <div class="col-md-6">
                <form action="" method="POST" class="tm-contact-form">
                    <div class="form-group">


                        <h3>Gmail:</h3>
                        <asp:TextBox ID="TextBox3" placeholder="eg. UserName@gmail.com" class="form-control" runat="server"></asp:TextBox>

                    </div>

                    <div class="form-group">
                        <h3>Password:</h3>
                        <asp:TextBox Type="password" ID="TextBox4" placeholder="Enter Your Password Here " class="form-control" runat="server"></asp:TextBox>

                    </div>

                    <div class="form-group tm-d-flex">
                        <h4 style="color: white;">Don't have an Account? </h4>
                        <a href="adminsignup.aspx" style="color: limegreen;">Sign Up Here </a>
                        <asp:Button ID="Button2" runat="server" class="tm-btn tm-btn-success tm-btn-right" Text="Login" OnClick="AdminLogin_Button_Click" />
                    </div>
                </form>
            </div>
        </div>
    </div>
    <br />
</asp:Content>
