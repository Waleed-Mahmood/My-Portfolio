import React, { useState } from 'react'
import { Paper, Tabs, Tab, Typography, Box } from '@material-ui/core';

import Login from './Login'
import Signup from './Signup'



function Admin() {
  
    const [value, setValue] = useState(0)
    const handleChange = (event, newValue) => {
      setValue(newValue);
    };
    const paperStyle = { padding: 20, height: '100vh', width: '50vw', margin: "0 auto", backgroundColor: '#B3E8E5', borderRadius:'40px' }
    function TabPanel(props) {
      const { children, value, index, ...other } = props;
      return (
        <div
          role="tabpanel"
          hidden={value !== index}
          id={`simple-tabpanel-${index}`}
          aria-labelledby={`simple-tab-${index}`}
          {...other}
        >
          {value === index && (
            <Box>
              <Typography>{children}</Typography>
            </Box>
          )}
        </div>
      );
    }
  
    return (
      <Paper elevation={20} style={paperStyle}>
        <Tabs
          value={value}
          indicatorColor="primary"
          textColor="primary"
          onChange={handleChange}
          aria-label="disabled tabs example"
        >
          <Tab label="Sign In" />
  
          <Tab label="Sign Up" />
        </Tabs>
        <TabPanel value={value} index={0}>
          <Login handleChange={handleChange} />
        </TabPanel>
        <TabPanel value={value} index={1}>
          <Signup />
        </TabPanel>
      </Paper>
  
    )
  
}

export default Admin