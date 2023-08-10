import React from 'react'
import './Home.css'
import Navbar from '../NavBar/Navbar'
import backvideo from '../../Assets/BackGround.mp4';
import { Container } from 'react-bootstrap';

export default function Home() {
    return (
        <div id='home'>
            <div className='homeBody'>
                <Navbar />
                <video autoPlay loop muted>
                    <source src={backvideo} type='video/mp4' />
                </video>
                <div className='content'>
                    <h1>Welcome to Quick Serve </h1>
                </div>
            </div>
        </div>
    )
}