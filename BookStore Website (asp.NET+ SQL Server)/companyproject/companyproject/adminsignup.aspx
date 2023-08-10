<%@ Page Title="" Language="C#" MasterPageFile="~/bookstore.Master" AutoEventWireup="true" CodeBehind="adminsignup.aspx.cs" Inherits="companyproject.adminsignup" %>
<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
     <h3 id="bolde">ADMIN SIGNUP: </h3>

    <div class="tm-container-inner-2 tm-contact-section">
        <div class="row">
            <div class="col-md-6">
                <form action="" method="POST" class="tm-contact-form">

                    <div class="form-group">
                        <h3>Gmail:</h3>
                        <asp:TextBox ID="TextBox10" placeholder="Enter Gmail ( eg. user@gmail.com )" class="form-control" runat="server"></asp:TextBox>
                         <asp:RegularExpressionValidator ID="RegularExpressionValidator1" runat="server" ControlToValidate="TextBox10"
            ForeColor="Red" ValidationExpression="^([\w-\.]+)@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.)|(([\w-]+\.)+))([a-zA-Z]{2,4}|[0-9]{1,3})(\]?)$"
            Display = "Dynamic" ErrorMessage = "Invalid email address"/>
        <asp:RequiredFieldValidator ID="RequiredFieldValidator1" runat="server" ControlToValidate="TextBox10"
            ForeColor="Red" Display = "Dynamic" ErrorMessage = "*Required" />      
                    </div>

                    <div class="form-group">

                        <h3>FirstName:</h3>
                        <asp:TextBox ID="TextBox30" placeholder="Enter Your First Name Here" class="form-control" runat="server"></asp:TextBox>
                         <asp:RequiredFieldValidator ID="RequiredFieldValidator2" runat="server" ControlToValidate="TextBox30"
            ForeColor="Red" Display = "Dynamic" ErrorMessage = "*Required" />       
                    </div>
                    <div class="form-group">

                        <h3>LastName:</h3>
                        <asp:TextBox ID="TextBox40" placeholder="Enter Your Last Name Here" class="form-control" runat="server"></asp:TextBox>
                         <asp:RequiredFieldValidator ID="RequiredFieldValidator3" runat="server" ControlToValidate="TextBox40"
            ForeColor="Red" Display = "Dynamic" ErrorMessage = "*Required" />       

                    </div>

                <!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
                    <html xmlns="http://www.w3.org/1999/xhtml">
                    <title>Control Toolkit</title>
                    <asp:ScriptManager ID="asm" runat="server" />
                    </html>
                    <div class="form-group">
                        <h3>Password:</h3>
                        <asp:TextBox Type="password" ID="TextBox20" placeholder="Enter Your Password Here" class="form-control" runat="server"></asp:TextBox>
                        <ajaxToolkit:PasswordStrength ID="ps1" runat="server"
                            TargetControlID="TextBox20" RequiresUpperAndLowerCaseCharacters="true"
                            MinimumNumericCharacters="1" MinimumSymbolCharacters="1"
                            PreferredPasswordLength="8" DisplayPosition="RightSide"
                            StrengthIndicatorType="Text" />
                         <asp:RequiredFieldValidator ID="RequiredFieldValidator4" runat="server" ControlToValidate="TextBox20"
            ForeColor="Red" Display = "Dynamic" ErrorMessage = "*Required" />       
                    </div>
                    <div class="form-group">
                        <h3>CNIC:</h3>
                        <asp:TextBox ID="TextBox60" placeholder="Enter CNIC (eg. 34010-0273631-1) " class="form-control" runat="server"></asp:TextBox>
                         <asp:RequiredFieldValidator ID="RequiredFieldValidator5" runat="server" ControlToValidate="TextBox60"
            ForeColor="Red" Display = "Dynamic" ErrorMessage = "*Required" />       
                    </div>
                    <div class="form-group tm-d-flex">

                        <asp:Button ID="SignUpButton" runat="server" class="tm-btn tm-btn-success tm-btn-right" Text="Signup" OnClick="SignUpButton_AClick" />

                    </div>
                </form>
            </div>
        </div>
    </div>
    <br />
</asp:Content>
