import React, { useState } from 'react'
import './css/Signup.css'
import { Link } from 'react-router-dom';
// import Login from '../pages/Login';
function Signup() {
    const [inputs, setInputs] = useState({});

    const handleChange = (event) => {
        const name = event.target.name;
        const value = event.target.value;
        setInputs(values => ({ ...values, [name]: value }))
    }

    const handleSubmit = (event) => {
        event.preventDefault();
        if (inputs.password !== inputs.cpassword) {
            alert("Confirms Password must match Password")
        }
        if (!/^[A-Z0-9._%+-]+@[A-Z0-9.-]+\.[A-Z]{2,4}$/i.test(inputs.email))
            alert("Incorrect Email Address")
    }

    return (
        <div className='signup-container'>
            <div className='signup-box'>
                <span className='border-line'></span>
                <form onSubmit={handleSubmit}>
                    <h2>Sign Up</h2>
                    <div className='input-box'>
                        <input
                            type="username"
                            name="username"
                            value={inputs.username || ""}
                            onChange={handleChange}
                            required
                        />
                        <span>Username</span>
                        <i></i>
                    </div>
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
                    <div className='input-box'>
                        <input
                            type="text"
                            name="cpassword"
                            value={(inputs.cpassword) || ""}
                            onChange={handleChange}
                            required

                        />
                        <span>Confirm Password</span>
                        <i></i>
                    </div>

                    <Link to="/Login" className='input-link'>Already a Member? <br />LOGIN</Link>
                    <input type="submit" value="Sign Up" />
                </form>
            </div>
        </div>
    )
}

export default Signup