
import './App.css';
import Navbar from './components/NavBar/Navbar';
import TeamWrapper from './components/Team/Teamindex'
import Contacts from './components/contact/contact'
import Signin from './components/Sign/Login'
import Signup from './components/Sign/Signup'
import Admin from './components/Sign/index';
import Services from './components/Service/services';
import { useState, useEffect } from 'react';
import Bottomnav from './components/NavBar/Bottomnav';
import Allgigs from './components/Service/Allgigs'
import { BrowserRouter, Routes, Route } from "react-router-dom";
import Home from './components/Home/Home';
function App() {
  const [windowDimenion, detectHW] = useState({
    winWidth: window.innerWidth,
    winHeight: window.innerHeight,
  })
  const detectSize = () => {
    detectHW({
      winWidth: window.innerWidth,
      winHeight: window.innerHeight,
    })
  }
  useEffect(() => {
    window.addEventListener('resize', detectSize)
    return () => {
      window.removeEventListener('resize', detectSize)
    }
  }, [windowDimenion])
  return (
    <div className="App">
      <Bottomnav />
      <Navbar />
      <Home/>
      <Services/>
      <br/>
      <br/>
      <br/>
      <br/>
      <Allgigs/>
      <TeamWrapper/>
      <Contacts/>
      <Admin/>
      {/* <div className='empty'></div> */}
      {/* <BrowserRouter>
        <Bottomnav />
        <Navbar />
        <Routes>
          <Route path="/" element={<Home />}></Route>
          <Route path="/home" element={<Home />}></Route>
          <Route path=" contact" element={<Contacts />}></Route>
          <Route path="/signin" element={<Signin />}></Route>
          <Route path="/signup" element={<Signup />}></Route>
          <Route path="/team" element={<TeamWrapper />}></Route>
          <Route path="/services" element={<Services />}></Route>
        </Routes>
      </BrowserRouter> */}
      

    </div>
  );
}

export default App;

// {/* <div className="App">
// <Navbar />
// <Bottomnav />
// <div className='empty'></div>
// <MHeader />
// <DiffServices />
// <AllGigs />
// <SHeader />
// <Route path='teams' element={<TeamWrapper/>}/>
// {/* <TeamWrapper /> */}
// <Contacts />
// <Admin />
// </div> */}