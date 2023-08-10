import React from 'react';
import './App.css';
import Navbar from './components/Navbar';
import Footer from './components/Footer';
import { BrowserRouter as Router, Routes, Route } from 'react-router-dom';
import Home from './pages/Home';
import Signup from './pages/Signup';
import Login from './pages/Login';
import Genre from './pages/Genre';
import Movies from './pages/Movies';
import TvSeries from './pages/TvSeries';
import Location from './pages/Location';
import Contact from './pages/Contact';
import About from './pages/About';
import BlogsHome from './pages/BlogsHome';
import Blog from './pages/Blog';
import BioGallery from './pages/BioGallery';
import Biography from './pages/Biography';
import Admin from './pages/Admin';
import Movie from './pages/Movie';
import '@progress/kendo-theme-default/dist/all.css';
import MembershipPage from './pages/MembershipPage';
import PaymentConfirmationPage from './components/PaymentConfirmation';

function App() {
  // button.onclick = function () {
  //   var div = document.getElementById('footer');
  //   
  // };
  return (
    <div className='main-app'>
      <Router>
        <Navbar />
        <Routes>
          <Route path='/' exact element={<Home />} />
          <Route path='/Genre' element={<Genre />} />
          <Route path='/Movies' element={<Movies />} />
          <Route path='/Movies/:searchKeyword?' element={<Movies />} />
          <Route path='/Movie/:id' element={<Movie />} />
          <Route path='/TvSeries' element={<TvSeries />} />
          <Route path='/Login' element={<Login />} />
          <Route path='/Signup' element={<Signup />} />
          <Route path='/Location' element={<Location />} />
          <Route path='/Contact' element={<Contact />} />
          <Route path='/Blog/:id' element={<Blog />} />
          <Route path='/BlogsHome' element={<BlogsHome />} />
          <Route path='/Biography/:id' element={<Biography />} />
          <Route path='/BioGallery' element={<BioGallery />} />
          <Route path='/MembershipPage' element={<MembershipPage />} />
          <Route path='/Payment-Confirmation' element={<PaymentConfirmationPage />} />


          <Route path='/About' element={<About />} />
          <Route path='/Admin' element={<Admin />} />
        </Routes>
        <Footer />
      </Router>
    </div>
  );
}
export default App;
