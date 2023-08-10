import React from 'react';
import ReactDOM from 'react-dom/client';
import './index.css';
import App from './App';
import { Auth0Provider } from "@auth0/auth0-react";
import { store } from './store';
import { Provider } from 'react-redux';

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(
  <Auth0Provider
    domain="dev-enspegs6mruj6y26.us.auth0.com"
    clientId="ofqyRTSdx1IK58A3bZcgYbQnPJlD5beI"
    authorizationParams={{
      redirect_uri: window.location.origin
    }}
  >
    {/* <React.StrictMode> */}
    <Provider store={store}>
      <App />
    </Provider>
    {/* </React.StrictMode> */}
  </Auth0Provider>,
);


