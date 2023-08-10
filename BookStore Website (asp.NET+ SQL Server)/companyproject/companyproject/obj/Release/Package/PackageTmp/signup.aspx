<%@ Page Title="" Language="C#" MasterPageFile="~/bookstore.Master" AutoEventWireup="true" CodeBehind="signup.aspx.cs" Inherits="companyproject.signup" %>
   
<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content> <asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
    <h3 Id="bolde">USER SIGNUP: </h3>

    <div class="tm-container-inner-2 tm-contact-section">
        <div class="row">
            <div class="col-md-6">
                <form action="" method="POST" class="tm-contact-form">


                    <div class="form-group">

                        <h3>FirstName:</h3>
                        <asp:TextBox ID="TextBox3" placeholder="Enter Your First Name Here" class="form-control" runat="server"></asp:TextBox>

                    </div>
                    <div class="form-group">

                        <h3>LastName:</h3>
                        <asp:TextBox ID="TextBox4" placeholder="Enter Your Last Name Here" class="form-control" runat="server"></asp:TextBox>


                    </div>

                    <div class="form-group">
                        <h3>Gender(M/F):</h3>
                        <asp:TextBox ID="TextBox5" placeholder="Enter Your Gender Here" class="form-control" runat="server"></asp:TextBox>
                    </div>

                    <div class="form-group">
                        <h3>Gmail:</h3>
                        <asp:TextBox ID="TextBox1" placeholder="Enter Gmail ( eg. user@gmail.com ) " class="form-control" runat="server"></asp:TextBox>
                          </div>

                        <!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
                        <html>                    
                         <title>Control Toolkit</title>                                                          
                         <asp:ScriptManager ID="asm" runat="server" />
                
                       <div class="form-group">
                        <h3>Password:</h3>
                        <asp:TextBox Type="password" ID="TextBox2" placeholder="Enter Your Password Here" class="form-control" runat="server"></asp:TextBox>
                         <ajaxToolkit:PasswordStrength ID="ps1" runat="server"                           
                         TargetControlID="TextBox2" RequiresUpperAndLowerCaseCharacters="true" 
                         MinimumNumericCharacters="1" MinimumSymbolCharacters="1" 
                         PreferredPasswordLength="8" DisplayPosition="RightSide" 
                         StrengthIndicatorType="Text" />

                    </div>
                    <div class="form-group">
                        <h3>Address:</h3>
                        <asp:TextBox  ID="TextBox6" placeholder="Enter Your Address Here" class="form-control" runat="server" ></asp:TextBox>                                                

                        <div class="form-group">
                        <h3>Membership(1/0):</h3>
                        <asp:TextBox ID="TextBox7" placeholder="Enter Your Membership Here" class="form-control" runat="server"></asp:TextBox>

                    </div>
                        
                          <%--   <asp:TextBox  id="TextBox6" runat="server" />
                       <asp:regularexpressionvalidator display="Dynamic" id="RegularExpressionValidator1"
                       errormessage="Password must be 8-10 characters long with at least one numeric,</br>one upper case character and one special character." forecolor="Red" validationexpression="(?=^.{8,10}$)(?=.*\d)(?=.*[a-z])(?=.*[A-Z])(?=.*[!@#$%^&*()_+}{:;'?/>.<,])(?!.*\s).*$" controltovalidate="TextBox6" runat="server">
</asp:regularexpressionvalidator>  </asp:TextBox>   --%>                

                    </div>
                    <div class="form-group tm-d-flex">

                        <asp:Button ID="SignUpButton" runat="server" class="tm-btn tm-btn-success tm-btn-right" Text="Signup" OnClick="SignUpButton_Click" />
                        
                    </div>
                </form>
            </div>
        </div>
    </div>
    <br />
</asp:Content>
