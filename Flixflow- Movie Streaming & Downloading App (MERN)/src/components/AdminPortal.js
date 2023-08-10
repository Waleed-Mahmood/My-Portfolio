import React, { useState, useEffect } from 'react';
import { MovieData } from './MovieData';
import "./AdminPortal.css";
// "https://upload.wikimedia.org/wikipedia/en/d/d2/Plane_%282023_film%29_poster.png" for movie plane
const AdminPortal = () => {
    const filteredList = MovieData.filter((i, index) => (index < 6));
    const [movieList, setMovieList] = useState(JSON.parse(JSON.stringify(filteredList)));
    const [newMovie, setNewMovie] = useState({
        title: '',
        year: '',
        thumbnail: '',
        extract: '',
    });
    const [showAddNewMovieForm, setShowAddNewMovieForm] = useState(false);
    const [showUpdateMovieForm, setShowUpdateMovieForm] = useState(false);
    const [showDeleteMovieForm, setShowDeleteMovieForm] = useState(false);


    useEffect(() => {
        // Retrieve movie list from local storage on page load
        const storedMovieList = localStorage.getItem('movieList');
        if (storedMovieList) {
            setMovieList(JSON.parse(storedMovieList));
        }
    }, []);

    useEffect(() => {
        // Update local storage whenever movieList changes
        localStorage.setItem('movieList', JSON.stringify(movieList));
    }, [movieList]);

    const handleAddNewButtonClick = () => {
        setShowAddNewMovieForm((prevValue) => !prevValue);
    };

    const handleUpdateButtonClick = () => {
        setShowUpdateMovieForm((prevValue) => !prevValue);
        // setShowAddNewMovieForm((prevValue) => !prevValue);
    };

    const handleDeleteButtonClick = () => {
        setShowDeleteMovieForm((prevValue) => !prevValue);
    };

    // Handle form input change
    const handleAddChange = (event) => {
        const { name, value } = event.target;
        setNewMovie((prevMovie) => ({
            ...prevMovie,
            [name]: value,
        }));
    };

    // Handle form submission
    const handleAddSubmit = (event) => {
        event.preventDefault();
        setMovieList((prevMovieList) => [...prevMovieList, newMovie]);
        setNewMovie({
            title: '',
            year: '',
            thumbnail: '',
            extract: '',
        });
    };


    const handleDeleteFormSubmit = (e) => {
        e.preventDefault();
        // Get the input values from the form
        const { title } = e.target.elements;
        // Delete the movie with the provided title
        handleDeleteSubmit(title.value);
        // Reset the form
        e.target.reset();
    };
    const handleDeleteSubmit = (title) => {
        const updatedList = movieList.filter((movie) => movie.title !== title);
        setMovieList(updatedList);
    };

    const handleUpdateFormSubmit = (e) => {

        e.preventDefault();
        // Get the input values from the form
        const { oldTitle, newTitle, newYear, newExtract, newThumbnail } = e.target.elements;

        // Find the movie with the matching old title
        const movieToUpdate = movieList.find((movie) => movie.title === oldTitle.value);
        // console.log("ot", oldTitle);
        // console.log("otv", oldTitle.value);

        if (movieToUpdate) {
            // Create an updated movie object
            const updatedMovie = {
                title: newTitle.value || movieToUpdate.title,
                year: newYear.value || movieToUpdate.year,
                extract: newExtract.value || movieToUpdate.description,
                thumbnail: newThumbnail.value || movieToUpdate.thumbnail,
            };

            // Update the movie in the movie list
            const updatedList = movieList.map((movie) =>
                movie.title === oldTitle.value ? updatedMovie : movie
            );
            setMovieList(updatedList);

            // Reset the form
            e.target.reset();
        } else {
            // Handle case when movie is not found
            console.log("Movie not found");
        }
    };

    return (
        <div className='admin-container'>
            <h1 style={{ margin: '100px', textAlign: 'center' }}>Admin Portal</h1>
            {/* <button onClick={loadData}>Show Movies</button> */}
            {movieList &&
                <div className="admin-movie-grid">
                    {movieList.map((movie) => (
                        <div className="admin-movie-card" key={movie.id}>
                            <h2 style={{ margin: '10px', textAlign: 'center' }}>{movie.title}-{movie.year}</h2>
                            {/* //movie.thumbnail_width */}
                            <img src={movie.thumbnail} style={{ width: "380px", height: "500px" }} alt="poster"></img>
                        </div>
                    ))}
                </div>
                //     movieList.map((movie) => (
                // <li key={movie.id}>
                //     
                // </li>
                // ))
            }

            <div className='submit-buttons'>
                <button onClick={handleAddNewButtonClick}>Add New Movies</button>
                <button onClick={handleUpdateButtonClick}>Update Existing Movies</button>
                <button onClick={handleDeleteButtonClick}>Delete Existing Movies</button>
            </div>



            {
                showAddNewMovieForm && (
                    <form onSubmit={handleAddSubmit}>
                        <div>
                            <label htmlFor="title">Title:</label>
                            <input type="text" id="title" name="title" value={newMovie.title} onChange={handleAddChange} required />
                        </div>
                        <div>
                            <label htmlFor="year">Year:</label>
                            <input type="text" id="year" name="year" value={newMovie.year} onChange={handleAddChange} required />
                        </div>
                        <div>
                            <label htmlFor="thumbnail">Thumbnail:</label>
                            <input
                                type="text"
                                id="thumbnail"
                                name="thumbnail"
                                value={newMovie.thumbnail}
                                onChange={handleAddChange}
                                required
                            />
                        </div>
                        <div>
                            <label htmlFor="extract">extract:</label>
                            <textarea
                                id="extract"
                                name="extract"
                                value={newMovie.extract}
                                onChange={handleAddChange}
                                required
                            ></textarea>
                        </div>
                        <button type="submit">Add Movie</button>
                    </form>
                )
            }

            {
                showUpdateMovieForm && (
                    <form onSubmit={handleUpdateFormSubmit}>

                        <div>
                            <label htmlFor="title">Old Title:</label>
                            <input type="text" name="oldTitle" placeholder="Old Title" required />
                        </div>

                        <div>
                            <label htmlFor="newtitle">New Title:</label>
                            <input type="text" name="newTitle" placeholder="New Title" />
                        </div>

                        <div>
                            <label htmlFor="year">Year:</label>
                            <input type="text" name="newYear" placeholder="New Year" />
                        </div>
                        <div>
                            <label htmlFor="thumbnail">Thumbnail:</label>
                            <input type="text" name="newThumbnail" placeholder="New Thumbnail URL" />
                        </div>
                        <div>
                            <label htmlFor="extract">Description:</label>
                            <textarea
                                id="newExtract"
                                name="newExtract"
                                placeholder='New Description'
                            ></textarea>
                        </div>
                        <button type="submit">Update Movie</button>

                    </form>
                )
            }
            {
                showDeleteMovieForm && (
                    <form onSubmit={handleDeleteFormSubmit}>
                        <div>
                            <label htmlFor="title">Title:</label>
                            <input type="text" id="title" name="title" required />
                        </div>
                        <button type="submit">Delete Movie</button>
                    </form>
                )
            }
            {/* <ul>
                {
                    filteredList.map((movie) => (
                        <li>
                            {movie.title}
                            <img src={movie.thumbnail} style={{ width: movie.thumbnail_width, height: movie.thumbnail_height }} alt="poster"></img>
                        </li>
                    ))
                }
            </ul> */}
        </div>
    );
};

export default AdminPortal;