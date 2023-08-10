import React, { useState } from 'react'
import { Paper } from '@mui/material';
import { Tabs } from '@mui/material';
import { Tab } from '@mui/material';
import { Typography } from '@mui/material';
import { Box } from '@mui/system';
import Login from '../Sign/Login'
import Signup from '../Sign/Signup' 
import { Padding } from '@mui/icons-material';


const SignInOutContainer=()=>{
    const [value,setValue]=useState(0)
    const handleChange = (event, newValue) => {
        setValue(newValue);
      };
      const paperStyle={padding: 20, height: '100vh', width: '60vw', margin: "0 auto", backgroundColor: '#B3E8E5', borderRadius:'40px'}
  function TabPanel(props) {
    const { children, value, index, ...other } = props;
    return (
        <div
          className='TabContainer'
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
        <Paper elevation={20} style={paperStyle}
          
        >
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
       <Login handleChange={handleChange}/>
      </TabPanel>
      <TabPanel value={value} index={1}>
      <Signup/>
      </TabPanel>
      </Paper>
      
    )
}



export default SignInOutContainer