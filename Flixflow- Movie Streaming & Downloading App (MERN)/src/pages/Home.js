import React, { useEffect, useState } from 'react'
import MovieServiceApi from '../api/MovieServiceApi'
// import { APIKey } from '../api/MovieApiKey'
import MovieList from '../components/MovieList';
// import Player from '../components/Player';


function Home() {
    return (
        <>
            <div style={{ color: 'White', margin: '200px', textAlign: 'center' }}>
                <h1> Home Page</h1 >
                {/* <MovieList /> */}
                {/* <Player /> */}

            </div >

        </>
    );
}

export default Home