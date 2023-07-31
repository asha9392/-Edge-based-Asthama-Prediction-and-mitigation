# -Edge-based-Asthama-Prediction-and-mitigation
Predicting the risk of asthama based on room temperature and humidity using machine learning
Air pollution is a problematic risk factor for death worldwide and is particularly important in several respiratory diseases. Additionally, it causes about 8 million deaths annually, with 4.2 million of those deaths occurring globally due to outdoor exposure and 3.8 million due to interior pollution. Pollutants cause a variety of respiratory problems. The number of asthma outcomes including incidence, prevalence, hospital admissions, visits to emergency rooms, mortality, and asthma episodes, among others, are also clearly impacted. Admission to the hospital is risky for elderly patients and those with multiple comorbidities including hypertension and diabetes, especially in the current covid situations. An internal monitoring strategy for predicting asthma is necessary to get around this. Therefore, a deep learning-based edge aided framework for asthma risk prediction (EARPM) is presented to accomplish the objective. Using a convolution neural network and the amount of particulate matter(pm) presenting in their living environment and the weather outside, E-ARP calculates the vulnerability level of peak exploratory flow rate. Additionally, the projected PEFR levels are divided into 3 classes based on best peak flow value that each participant was able to obtain:
“Green” , “Yellow”  and “Red” based on the level of risk. Countermeasures like turning on sir purifiers should be taken if the current conditions are conductive to raising the risk of asthma.PM sensors are used in the hardware implementation of the E-RMP prototype to find the particulate matter. Additionally, Raspberry Pi serves as an edge node that forecasts the degree of risk and triggers the reaction system(purifiers) in response.
KEYWORDS-edge computing, machine learning, iot, Asthma prediction, particulate matter (PM), peak expiratory flow rates (PEFR), convolutional neural network, Raspberry pi. 


1.1	DETAILS OF THE BASE PAPER 
Base Paper Title: Machine Learning-Based Asthma Risk Prediction Using IoT and      
                              Smart phone Applications
Publisher: IEEE Internet of things journal
Year of Publication :2021

1.2	INTRODUCTION 
Chronic airway inflammation known as asthma is characterized by episodes of wheezing, throat tightness, coughing and shortness of breath. An abrupt decline in these is an asthma attack, which may be fatal, is one of the symptoms. Chronic obstructive pulmonary disease (COPD), which encompasses emphysema and chronic bronchitis, is another severe, irreversible airflow obstruction in the lungs. Asthma limits social, emotional and physical elements of life, which lowers the quality of life for people of all ages.
                         Forecasting health hazards and incorporating them into a person's lifestyle can improve their quality of life .When it comes to asthma, environmental health is a significant factor. Weather and indoor air pollution can both be significant indicators of asthma. Today's non-invasive approaches for diagnosing and managing asthma do not accurately characterize the level of airway inflammation and call for pricey equipment that patients may not be able to pay.
Therefore, reliable counsel for patients to seek appropriate care or take drugs to feel better, may be provided by excellent predictive modelling. In the proposed method, the risk of an asthma attack is predicted using an air quality monitoring system and the weather report.

Algorithm: 
The algorithm describing the real-time operation of the suggested system PM2.5,PM 10,ambient temperature ,and humidity are all inputs. Safe, moderate, or high asthma risk prediction as an output. Stage of the Raspberry Pi’s data processing: Utilize SDS011 to collect PM2.5 and PM10; utilizing the DHT11 sensor, collect weather data; data hosting the server’s input features; Stage in real time with a smartphone.

while MQTT publishing data: 
	 do Collect data from Sensor;
	 CNN prediction;
	 if PEFR > 80% then 
		Safe; 
	else if 50% < PEFR < 80% then 
		Moderate risk;
	 else 
		High risk;
	 end
end

SUMMARY OF THE BASE PAPER



The proposed model predicts the environmental status with the help of Air Quality Sensor.SDS011 sensor is used for collecting the PM2.5 and PM10 values. Along with this we use DHT11 sensor to get the temperature and humidity of the area the person present. The data from these sensors is collected by ESP32 and published to Raspberry pi with the help of MQTT communication protocol. The model is built using CNN algorithm which is more efficient in prediction. The model is trained with a real time dataset. The dataset also consists of age, height and PERF which varies from person to person. The age and height of a person is also a depending factor on the prediction.
We utilize a smartphone, sensors, and an IOT platform for real-time asthma risk prediction. Data from an air quality monitor is gathered using a Raspberry Pi. The weather information is gathered from a DHT11 sensor. On a secure server, both the Raspberry Pi data and the meteorological data are stored. The Raspberry pi then uses this information to turn on the air purifier. The trained neural network model is packaged with a Raspberry Pi, which retrieves the necessary input data for the model from the server and forecasts the risk for asthma. Two stages—the data processing stage on the Raspberry Pi and the real-time stage on the active Air purifier—are used to illustrate the tool's complete workflow in Algorithm 1. Further, the performance of the proposal is compared with other deep learning models like ANN, DNN and FCN based on metrics such as Root Mean Square error and Mean absolute error.  based. Based on the results, it is found that the RMSE and MAE of CNN is (51.70%,57.7%), (46.50%,52.00%) and (12.63%,19.69%) better than that of ANN, DNN, FCN respectively thereby demonstrating the efficacy of the proposal in accurately predicting the ambience condition amenable to cause asthma attack.



PROPOSED METHODOLOGY

Proposed Asthma Prediction Method 
Prediction of asthma is based on the particulate matter present in air, temperature , humidity and persons age , height.
Air quality sensor, DHT11 are used for the model 
Data is collected from the sensors and deep learning convolutional neural network used for model training
The data is published to raspberry pi and the trained model is deployed in raspberry pi .Prediction of level of risk is done at raspberry pi. 
A.PEAK EXPLORATORY FLOW RATE (PEFR)
Pulmonary function tests (PFT) are the real approach for identifying and treating respiratory issues, however it is challenging to gather PFT data using self-administered home tests. Therefore, PEFR is simple to use and provides an accurate result for a person utilizing a small, portable peak-flow metre at home. PEFR levels have been divided into three groups in the suggested methodology:

Green: a normal exacerbation when the value exceeds 80% of the best peak flow.
Yellow: Moderate aggravation when the measurement is between 50% and 80% of the best peak flow.
Red: Significant aggravation when the reading is below 50% of the best peak flow

Safe, Moderate, Risk are the labels used for neural network modeling and these categories are used as output displayed by hardware using LEDs. 

B.INDOOR AIR MONITORING
Air contains particulate matter and the main particulate matters to be measured for asthma prediction is PM2.5 and PM10. These measurements were made during the same period that the PEFR data were gathered. These values are correlated for a certain time interval.

C.MONITORING TEMPERATURE AND HUMIDITY
Environmental temperature and humidity are also one of the major factors that causes asthma .The conditions of the environment is monitored using DHT11.Temperature and humidity of the certain place is measured.




