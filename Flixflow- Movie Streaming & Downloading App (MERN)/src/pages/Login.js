import React, { useState } from 'react'
import "./css/login.css"
import { Link } from 'react-router-dom';
// import Login from '../pages/Login';
function Login() {
    const [inputs, setInputs] = useState({});

    const handleChange = (event) => {
        const name = event.target.name;
        const value = event.target.value;
        setInputs(values => ({ ...values, [name]: value }))
    }

    const handleSubmit = (event) => {
        event.preventDefault();
        console.log(inputs);
    }

    return (
        <div className='login-container'>
            <div className='login-box'>
                <span className='border-line'></span>
                <form onSubmit={handleSubmit}>
                    <h2>Log In</h2>
                    <div className='input-box'>
                        <input
                            type="email"
                            name="email"
                            value={inputs.email || ""}
                            onChange={handleChange}
                            required
                        />
                        <span>Email</span>
                        <i></i>
                    </div>
                    <div className='input-box'>
                        <input
                            type="text"
                            name="password"
                            value={inputs.password || ""}
                            onChange={handleChange}
                            required
                        />
                        <span>Password</span>
                        <i></i>
                    </div>

                    <Link to="/Signup" className='input-link'>Not Registered?<br /> SIGNUP</Link>
                    <input type="submit" value="Log In" />
                </form>
            </div>
        </div>
    )
}

export default Login