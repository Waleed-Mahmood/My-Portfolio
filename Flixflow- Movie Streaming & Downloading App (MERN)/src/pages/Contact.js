/* eslint-disable jsx-a11y/iframe-has-title */
import React from 'react'
import '../pages/css/contact.css'

function Contact() {
    return (
        <>
            <div style={{ margin: '50px', textAlign: 'center' }}>
                <h1 style={{ color: 'white', textTransform: 'capitalize', marginBottom: '30px' }}>Feel Free to Contact us</h1>
                <iframe src="https://www.google.com/maps/embed?pb=!1m14!1m8!1m3!1d13610.206048358172!2d74.3030141!3d31.4815212!3m2!1i1024!2i768!4f13.1!3m3!1m2!1s0x391903f08ebc7e8b%3A0x47e934f4cd34790!2sFAST%20NUCES%20Lahore!5e0!3m2!1sen!2s!4v1681610757653!5m2!1sen!2s"
                    width="600"
                    height="450"
                    style={{ border: '0' }}
                    allowFullScreen=""
                    loading="lazy"
                    referrerpolicy="no-referrer-when-downgrade">
                </iframe>

            </div>

            <div className="container">
                <div className="contact-form">
                    <form
                        action="#"
                        method="POST"
                        className="contact-inputs">
                        <input
                            className='input-field'
                            type="text"
                            name="username"
                            placeholder="Username"
                            autoComplete="off"
                            required
                        />

                        <input
                            className='input-field'
                            type="email"
                            name="Email"
                            placeholder="Email"
                            autoComplete="off"
                            required
                        />

                        <textarea
                            name="message"
                            cols="30"
                            rows="6"
                            placeholder="Write message"
                            autoComplete="off"
                            required></textarea>


                        <input type="submit" value="SEND" />
                    </form>
                </div>
            </div>
        </>
    )
}

export default Contact