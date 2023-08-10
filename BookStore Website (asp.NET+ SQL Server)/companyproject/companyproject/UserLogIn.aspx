<%@ Page Title="" Language="C#" MasterPageFile="~/bookstore.Master" AutoEventWireup="true" CodeBehind="UserLogIn.aspx.cs" Inherits="companyproject.UserLogIn" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
    <h3 id="bolde">USER LOGIN:</h3>
    <div class="tm-container-inner-2 tm-contact-section">
        <div class="row">
            <div class="col-md-6">
                <form action="" method="POST" class="tm-contact-form">
                    <div class="form-group">


                        <h3>GMAIL:</h3>
                        <asp:TextBox ID="TextBox3" placeholder="eg. UserName@gmail.com" class="form-control" runat="server"></asp:TextBox>
                         <asp:RequiredFieldValidator ID="RequiredFieldValidator3" runat="server" ControlToValidate="TextBox3"
            ForeColor="Red" Display = "Dynamic"  ErrorMessage = "*Required" />
                    </div>

                    <div class="form-group">
                        <h3>Password:</h3>
                        <asp:TextBox Type="password" ID="TextBox4" placeholder="Enter Your Password Here " class="form-control" runat="server"></asp:TextBox>
                         <asp:RequiredFieldValidator ID="RequiredFieldValidator1" runat="server" ControlToValidate="TextBox4"
            ForeColor="Red" Display = "Dynamic"  ErrorMessage = "*Required" />
                    </div>

                    <div class="form-group tm-d-flex">
                        <h4 style="color: white;">Don't have an Account? </h4>
                        <a href="signup.aspx" style="color: limegreen;">Sign Up Here </a>
                        <asp:Button ID="Button2" runat="server" class="tm-btn tm-btn-success tm-btn-right" Text="Login" OnClick="UserLogIn_Button_Click" />
                    </div>
                </form>
            </div>
        </div>
    </div>
    <br />
</asp:Content>
