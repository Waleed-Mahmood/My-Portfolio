import React from 'react'
import './Footer.css'
import * as SoIcons from '@fortawesome/free-brands-svg-icons'
import { FontAwesomeIcon } from '@fortawesome/react-fontawesome'

function Footer() {
    return (
        <>
            <div className="m-0 p-0 box-border leading-normal">
                <footer className="bg-gray-900">
                    <div className="m-auto">
                        <div className="flex flex-wrap">
                            <div className="w-3/12">
                                <h4>company</h4>
                                <ul>
                                    <li><a href="#">about us</a></li>
                                    <li><a href="#">our services</a></li>
                                    <li><a href="#">privacy policy</a></li>
                                    <li><a href="#">affiliate program</a></li>
                                </ul>
                            </div>
                            <div className="footer-col">
                                <h4>get help</h4>
                                <ul>
                                    <li><a href="#">FAQ</a></li>
                                    <li><a href="#">shipping</a></li>
                                    <li><a href="#">returns</a></li>
                                    <li><a href="#">order status</a></li>
                                    <li><a href="#">payment options</a></li>
                                </ul>
                            </div>
                            <div className="footer-col">
                                <h4>online shop</h4>
                                <ul>
                                    <li><a href="#">watch</a></li>
                                    <li><a href="#">bag</a></li>
                                    <li><a href="#">shoes</a></li>
                                    <li><a href="#">dress</a></li>
                                </ul>
                            </div>
                            <div className="footer-col">
                                <h4 className='text-lg text-white capitalize mb-8 font-medium relative'>follow us</h4>
                                <div className="f-social-links">
                                    <a href="https://www.facebook.com/"><FontAwesomeIcon icon={SoIcons.faFacebook} /></a>
                                    <a href="https://twitter.com/"><FontAwesomeIcon icon={SoIcons.faTwitter} /></a>
                                    <a href="https://www.instagram.com/"><FontAwesomeIcon icon={SoIcons.faInstagram} /></a>
                                    <a href="https://pk.linkedin.com/"><FontAwesomeIcon icon={SoIcons.faLinkedinIn} /></a>
                                </div>
                            </div>
                        </div>
                    </div>
                </footer>
            </div>

        </>
    )
}

export default Footer