<%@ Page Title="" Language="C#" MasterPageFile="~/bookstore.Master" AutoEventWireup="true" CodeBehind="signup.aspx.cs" Inherits="companyproject.signup" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
    <h3 id="bolde">USER SIGNUP: </h3>

    <div class="tm-container-inner-2 tm-contact-section">
        <div class="row">
            <div class="col-md-6">
                <form action="" method="POST" class="tm-contact-form">
                               
                    <div class="form-group">
                        <h3>FirstName:</h3>
                        <asp:TextBox ID="TextBox3" class="form-control" ValidationGroup="LoginFrame" runat="server"></asp:TextBox>                       
                          <asp:RequiredFieldValidator ID="RequiredFieldValidator3" runat="server" ControlToValidate="TextBox3"
            ForeColor="Red" Display = "Dynamic"  ErrorMessage = "*Required" />

                    </div>

                    <div class="form-group">
                        <h3>LastName:</h3>
                        <asp:TextBox ID="TextBox4" class="form-control" runat="server"></asp:TextBox>
                          <asp:RequiredFieldValidator ID="RequiredFieldValidator4" runat="server" ControlToValidate="TextBox4"
            ForeColor="Red" Display = "Dynamic" ErrorMessage = "*Required" />

                    </div>

                    <div class="form-group">
                        <h3>Gender(M/F):</h3>
                        <asp:TextBox ID="TextBox5" class="form-control" runat="server"></asp:TextBox>
                          <asp:RequiredFieldValidator ID="RequiredFieldValidator5" runat="server" ControlToValidate="TextBox5"
            ForeColor="Red" Display = "Dynamic" ErrorMessage = "*Required" />

                    </div>

                    <div class="form-group">
                        <h3>Gmail:</h3>
                        <asp:TextBox ID="TextBox1" class="form-control" runat="server"></asp:TextBox>
                        
        <asp:RegularExpressionValidator ID="RegularExpressionValidator1" runat="server" ControlToValidate="TextBox1"
            ForeColor="Red" ValidationExpression="^([\w-\.]+)@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.)|(([\w-]+\.)+))([a-zA-Z]{2,4}|[0-9]{1,3})(\]?)$"
            Display = "Dynamic" ErrorMessage = "Invalid email address"/>
        <asp:RequiredFieldValidator ID="RequiredFieldValidator1" runat="server" ControlToValidate="TextBox1"
            ForeColor="Red" Display = "Dynamic" ErrorMessage = "*Required" />                   
                          </div>

                        <!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
                        <html xmlns="http://www.w3.org/1999/xhtml">                                                                            
                         <asp:ScriptManager ID="asm" runat="server" />
                
                       <div class="form-group">
                        <h3>Password:</h3>
                        <asp:TextBox Type="password" ID="TextBox2" class="form-control" runat="server"></asp:TextBox>
                         <ajaxToolkit:PasswordStrength ID="ps1" runat="server"                           
                         TargetControlID="TextBox2" RequiresUpperAndLowerCaseCharacters="true" 
                         MinimumNumericCharacters="1" MinimumSymbolCharacters="1" 
                         PreferredPasswordLength="8" DisplayPosition="RightSide" 
                         StrengthIndicatorType="Text" />

                             <asp:RequiredFieldValidator ID="RequiredFieldValidator6" runat="server" ControlToValidate="TextBox2"
            ForeColor="Red" Display = "Dynamic" ErrorMessage = "*Required" />

                    <div class="form-group">
                        <h3>Address:</h3>
                        <asp:TextBox  ID="TextBox6" class="form-control" runat="server" ></asp:TextBox>  
        <asp:RequiredFieldValidator ID="RequiredFieldValidator2" runat="server" ControlToValidate="TextBox6"
            ForeColor="Red" Display = "Dynamic" ErrorMessage = "*Required" />

                         </div>

                        <div class="form-group">
                        <h3>Membership(1/0):</h3>
                        <asp:TextBox ID="TextBox7" class="form-control" runat="server"></asp:TextBox> 

                              <asp:RequiredFieldValidator ID="RequiredFieldValidator7" runat="server" ControlToValidate="TextBox7"
            ForeColor="Red" Display = "Dynamic" ErrorMessage = "*Required" />

                    </div>

                    <div class="form-group tm-d-flex">

                        <asp:Button ID="SignUpButton" runat="server" class="tm-btn tm-btn-success tm-btn-right" CausesValidation="true" Text="Signup"  />   <%--OnClick="SignUpButton_Click"--%>
                        
                    </div>
                </form>
            </div>
        </div>
    </div>
    <br />
   
</asp:Content>
