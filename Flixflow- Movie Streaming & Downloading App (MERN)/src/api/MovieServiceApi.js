import axios from 'axios';
import { APIKey } from './MovieApiKey';

const MovieServiceApi = {
    async getPopularMovies() {
        const url = `https://api.themoviedb.org/3/movie/popular?api_key=${APIKey}`;
        const response = await axios.get(url);
        return response.data.results;
    },

    async searchMovies(query) {
        const url = `https://api.themoviedb.org/3/search/movie?api_key=${APIKey}&query=${query}`;
        const response = await axios.get(url);
        return response.data.results;
    },

    async getMovieDetails(movieId) {
        const url = `https://api.themoviedb.org/3/movie/${movieId}?api_key=${APIKey}`;
        const response = await axios.get(url);
        return response.data;
    },

    async addMovie(movie) {
        const url = `https://api.themoviedb.org/3/movie?api_key=${APIKey}`;
        const response = await axios.post(url, movie);
        return response.data;
    },

    async updateMovie(movieId, movie) {
        const url = `https://api.themoviedb.org/3/movie/${movieId}?api_key=${APIKey}`;
        const response = await axios.put(url, movie);
        return response.data;
    },
    async deleteMovie(movieId) {
        const url = `https://api.themoviedb.org/3/movie/${movieId}?api_key=${APIKey}`;
        await axios.delete(url);
        return movieId;
    }
};


export default MovieServiceApi;


